cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
	src
)

add_executable(game
	src/game/main.cpp
)

add_library(engine
	src/engine/gameObject.cpp
	src/engine/gameObject.h
)