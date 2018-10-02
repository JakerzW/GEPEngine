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
	src/engine/gameObject.cpp
	src/engine/gameObject.h
)

target_link_libraries(game engine)