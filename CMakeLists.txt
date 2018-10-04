cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
	src
	contrib/glew/include
	contrib/SDL2/include
	contrib/SDL2_image/include
)

add_executable(game
	src/game/main.cpp
)

add_library(engine
	src/engine/core.cpp
	src/engine/core.h
	src/engine/gameObject.cpp
	src/engine/gameObject.h
	src/engine/component.cpp
	src/engine/component.h
	src/engine/input.cpp
	src/engine/input.h
	src/engine/context.cpp
	src/engine/context.h
)

target_link_libraries(game engine)