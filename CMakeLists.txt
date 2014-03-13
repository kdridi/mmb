cmake_minimum_required (VERSION 2.6)

project (Engine)

# The version number.
set (ENGINE_VERSION_MAJOR 1)
set (ENGINE_VERSION_MINOR 0)

set (ENGINE_RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################################################################################
configure_file (
	"${PROJECT_SOURCE_DIR}/engine.in.h"
	"${PROJECT_SOURCE_DIR}/include/engine.h"
)
set(ENGINE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

################################################################################
# GLEW
################################################################################
Find_Package ( GLEW REQUIRED )

if ( NOT GLEW_FOUND )
   message ( FATAL_ERROR "GLEW not found!" )
endif ( NOT GLEW_FOUND )

set(ENGINE_INCLUDE_DIRS ${ENGINE_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR}             )
set(ENGINE_LIBRARIES    ${ENGINE_LIBRARIES}    ${GLEW_LIBRARIES}               )

################################################################################
# OpenGL
################################################################################
include(FindOpenGL)

if ( NOT OPENGL_FOUND )
   message ( FATAL_ERROR "OpenGL not found!" )
endif ( NOT OPENGL_FOUND )

set(ENGINE_INCLUDE_DIRS ${ENGINE_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR}           )
set(ENGINE_LIBRARIES    ${ENGINE_LIBRARIES}    ${OPENGL_LIBRARIES}             )

################################################################################
# GLUT
################################################################################
include(FindGLUT)

if ( NOT GLUT_FOUND )
   message ( FATAL_ERROR "GLUT not found!" )
endif ( NOT GLUT_FOUND )

set(ENGINE_INCLUDE_DIRS ${ENGINE_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR}             )
set(ENGINE_LIBRARIES    ${ENGINE_LIBRARIES}    ${GLUT_LIBRARY}                 )

################################################################################
# SDL
################################################################################
include(FindSDL)

if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

set(ENGINE_INCLUDE_DIRS ${ENGINE_INCLUDE_DIRS} ${SDL_INCLUDE_DIR}              )
set(ENGINE_LIBRARIES    ${ENGINE_LIBRARIES}    ${SDL_LIBRARY}                  )

################################################################################
# CURL
################################################################################
include(FindCURL)

if ( NOT CURL_FOUND )
   message ( FATAL_ERROR "CURL not found!" )
endif ( NOT CURL_FOUND )

set(ENGINE_INCLUDE_DIRS ${ENGINE_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS}            )
set(ENGINE_LIBRARIES    ${ENGINE_LIBRARIES}    ${CURL_LIBRARIES}               )

################################################################################
include_directories( ${ENGINE_INCLUDE_DIRS} )
add_definitions(
	-Wall
	-Wextra
	# -Werror
	-D__GXX_EXPERIMENTAL_CXX0X__
)

################################################################################
add_executable(engine
	src/block.c
	src/block.h
	src/bubble.c
	src/bubble.h
	src/chunk.h
	src/chunkgen.c
	src/chunkgen.h
	src/chunksplit.c
	src/chunksplit.h
	src/cmwc.c
	src/cmwc.h
	src/defs.c
	src/defs.h
	src/generator.c
	src/generator.h
	src/main.c
	src/raytrace.c
	src/raytrace.h
	src/render.c
	src/render.h
	src/simplex.c
	src/simplex.h
	src/soil/SOIL.c
	src/soil/SOIL.h
	src/soil/image_DXT.c
	src/soil/image_DXT.h
	src/soil/image_helper.c
	src/soil/image_helper.h
	src/soil/stb_image_aug.c
	src/soil/stb_image_aug.h
	src/soil/stbi_DDS_aug.h
	src/soil/stbi_DDS_aug_c.h
	src/vector.h
	src/world.c
	src/world.h
	src/worldrender.c
	src/worldrender.h
)
target_link_libraries(engine ${ENGINE_LIBRARIES} )