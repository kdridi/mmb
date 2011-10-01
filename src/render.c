/* 
 * 
 * 
 * gcc -Wall -g -c render.c -o render
 * 
 * */

#include "render.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/freeglut.h>
#if !defined(GLUT_WHEEL_UP)
#  define GLUT_WHEEL_UP   3
#  define GLUT_WHEEL_DOWN 4
#endif

static Render render;

// =====================================================================

void moveCamera(float dx, float dy, float dz) {
	render.camera.x += dx;
	render.camera.y += dy;
	render.camera.z += dz;
	render.camera.ix = (int)floor(render.camera.x);
	render.camera.iy = (int)floor(render.camera.y);
	render.camera.iz = (int)floor(render.camera.z);
}

void renderDebug() {
	printf("===== RENDER DEBUG =====\n");
	printf("Camera: %1.1f/%1.1f/%1.1f %1.1f/%1.1f/%1.1f %i/%i/%i\n",
			render.camera.x,  render.camera.y,  render.camera.z,
			render.camera.dx, render.camera.dy, render.camera.dz,
			render.camera.ix, render.camera.iy, render.camera.iz);
	printf("Vertices drawn: %i\n", render.vertices);
	printf("===== END =====\n");
}

void onReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,			//The camera angle
			(double)w / (double)h,	//The width-to-height ratio
			1.0,			//The near z clipping coordinate
			200.0);			//The far z clipping coordinate
}

void onPassiveMotion(int x, int y) {
	int cx = glutGet(GLUT_WINDOW_WIDTH)/2;
	int cy = glutGet(GLUT_WINDOW_HEIGHT)/2;
	if (x - cx == 0 && y - cy == 0)
		return;

	render.mouseX = ( render.mouseX + x - cx ) % render.mouseSens;
	render.mouseY += y - cy;
	if (render.mouseY > render.mouseSens) render.mouseY = render.mouseSens;
	if (render.mouseY < 0) render.mouseY = 0;

	float ax = (float) -render.mouseY / render.mouseSens * M_PI;
	float ay = (float) -render.mouseX / render.mouseSens * M_PI * 2;
	render.camera.dx = sinf(ax) * sinf(ay);
	render.camera.dy = cosf(ax);
	render.camera.dz = sinf(ax) * cosf(ay);

	glutWarpPointer(cx, cy);
	glutPostRedisplay();
}

void onKeyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'w':
			moveCamera(render.camera.dx, render.camera.dy,
					render.camera.dz);
			break;
		case 's':
			moveCamera(-render.camera.dx, -render.camera.dy,
					-render.camera.dz);
			break;
		case 'a':
			moveCamera(render.camera.dz, 0, -render.camera.dx);
			break;
		case 'd':
			moveCamera(-render.camera.dz, 0, render.camera.dx);
			break;

		case 'q':
			glutLeaveMainLoop();
			break;
		case 'i':
			renderDebug();
			break;
		default:
			printf("No mapping for key %i\n", key);
			break;
	}
	glutPostRedisplay();
}

void onDisplay() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(render.camera.x, render.camera.y, render.camera.z,
			render.camera.x + render.camera.dx,
			render.camera.y + render.camera.dy,
			render.camera.z + render.camera.dz,
			0, 1, 0);

	GLfloat ambientColor[] = {1, 1, 1, 1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor[] = {0.5, 0.5, 1, 1};
	GLfloat lightPosition[] = {0, 1, 0, 0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	GLfloat lightColor1[] = {1, 0, 0, 1};
	GLfloat lightPosition1[] = {-1, 1, 0, 0};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

	render.vertices = 0;
	if (render.onDraw)
		render.onDraw(render.onDrawData);

	glutSwapBuffers();
}

Render *renderInit(int argc, char *argv[]) {
	memset(&render, 0, sizeof(Render));
	render.onDraw = NULL;
	render.onDrawData = NULL;

	render.mouseSens = 500;

	moveCamera(0, 10, 0);
	render.camera.dx = 0.6;
	render.camera.dy = -0.4;
	render.camera.dz = 0.7;


	glutInit(&argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
			GLUT_ACTION_CONTINUE_EXECUTION);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	render.window = glutCreateWindow("Mmb " VERSION);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glutReshapeFunc(&onReshape);
	glutPassiveMotionFunc(&onPassiveMotion);
	glutKeyboardFunc(&onKeyboard);
	glutDisplayFunc(&onDisplay);

	return &render;
}

void renderRun() {
	glutMainLoop();
}

void renderHookDraw(int (*func)(void *data), void *data) {
	render.onDraw = func;
	render.onDrawData = data;
}