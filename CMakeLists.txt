cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
	src
	contrib/glew/include
	contrib/SDL2/include
	contrib/SDL2_image/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/SDL2/lib
	${CMAKE_SOURCE_DIR}/contrib/SDL2_image/lib
	${CMAKE_SOURCE_DIR}/contrib/glew/lib	
)

add_executable(game
	src/game/main.cpp
)

add_library(engine
	src/engine/Core.cpp
	src/engine/Core.h
	src/engine/GameObject.cpp
	src/engine/GameObject.h
	src/engine/Component.cpp
	src/engine/Component.h
	src/engine/Input.cpp
	src/engine/Input.h
	src/engine/Context.cpp
	src/engine/Context.h
)

target_link_libraries(game engine)