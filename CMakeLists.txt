cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
	src
	contrib/SDL2/include
	contrib/SDL2_image/include
	contrib/glew/include
	contrib/glm
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/SDL2/lib
	${CMAKE_SOURCE_DIR}/contrib/SDL2_image/lib
	${CMAKE_SOURCE_DIR}/contrib/glew/lib	
)

add_library(engine
	src/engine/Component.cpp
	src/engine/Component.h
	src/engine/Context.cpp
	src/engine/Context.h
	src/engine/Core.cpp
	src/engine/Core.h
	src/engine/GameObject.cpp
	src/engine/GameObject.h
	src/engine/Input.cpp
	src/engine/Input.h
	src/engine/Renderer.cpp
	src/engine/Renderer.h
	src/engine/ShaderProgram.cpp
	src/engine/ShaderProgram.h
	src/engine/VertexArray.cpp
	src/engine/VertexArray.h
	src/engine/VertexBuffer.h
	src/engine/VertexBuffer.cpp
)

target_link_libraries(engine SDL2 glew32 opengl32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game engine)

