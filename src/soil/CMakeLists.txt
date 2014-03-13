cmake_minimum_required (VERSION 2.6)

project (SOIL)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################################################################################
# GLEW
################################################################################
Find_Package ( GLEW REQUIRED )

if ( NOT GLEW_FOUND )
   message ( FATAL_ERROR "GLEW not found!" )
endif ( NOT GLEW_FOUND )

set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR}                 )
set(SOIL_LIBRARIES    ${SOIL_LIBRARIES}    ${GLEW_LIBRARIES}                   )

################################################################################
# OpenGL
################################################################################
include(FindOpenGL)

if ( NOT OPENGL_FOUND )
   message ( FATAL_ERROR "OpenGL not found!" )
endif ( NOT OPENGL_FOUND )

set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR}               )
set(SOIL_LIBRARIES    ${SOIL_LIBRARIES}    ${OPENGL_LIBRARIES}                 )

################################################################################
# GLUT
################################################################################
include(FindGLUT)

if ( NOT GLUT_FOUND )
   message ( FATAL_ERROR "GLUT not found!" )
endif ( NOT GLUT_FOUND )

set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR}                 )
set(SOIL_LIBRARIES    ${SOIL_LIBRARIES}    ${GLUT_LIBRARY}                     )

################################################################################
# SDL
################################################################################
include(FindSDL)

if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIRS} ${SDL_INCLUDE_DIR}                  )
set(SOIL_LIBRARIES    ${SOIL_LIBRARIES}    ${SDL_LIBRARY}                      )

################################################################################
# CURL
################################################################################
include(FindCURL)

if ( NOT CURL_FOUND )
   message ( FATAL_ERROR "CURL not found!" )
endif ( NOT CURL_FOUND )

set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS}                )
set(SOIL_LIBRARIES    ${SOIL_LIBRARIES}    ${CURL_LIBRARIES}                   )

################################################################################
include_directories( ${SOIL_INCLUDE_DIRS} )
add_definitions(
	-Wall
	-Wextra
)

################################################################################
add_library(SOIL STATIC
	SOIL.c
	SOIL.h
	image_DXT.c
	image_DXT.h
	image_helper.c
	image_helper.h
	stb_image_aug.c
	stb_image_aug.h
	stbi_DDS_aug.h
	stbi_DDS_aug_c.h
)