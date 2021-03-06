cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
	src
	resources
	contrib/SDL2/include
	contrib/SDL2_image/include
	contrib/glew/include
	contrib/glm
	contrib/stb_image
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/SDL2/lib
	${CMAKE_SOURCE_DIR}/contrib/SDL2_image/lib
	${CMAKE_SOURCE_DIR}/contrib/glew/lib	
)

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(engine
	src/engine/Engine.h
	src/engine/Camera.cpp
	src/engine/Camera.h
	src/engine/Collision.cpp
	src/engine/Collision.h
	src/engine/Component.cpp
	src/engine/Component.h
	src/engine/Context.cpp
	src/engine/Context.h
	src/engine/Core.cpp
	src/engine/Core.h
	src/engine/GameObject.cpp
	src/engine/GameObject.h
	src/engine/ID.cpp
	src/engine/ID.h
	src/engine/Input.cpp
	src/engine/Input.h
	src/engine/Player.cpp
	src/engine/Player.h
	src/engine/Renderer.cpp
	src/engine/Renderer.h
	src/engine/Screen.cpp
	src/engine/Screen.h
	src/engine/ShaderProgram.cpp
	src/engine/ShaderProgram.h
	src/engine/Texture.cpp
	src/engine/Texture.h
	src/engine/Transform.cpp
	src/engine/Transform.h
	src/engine/VertexArray.cpp
	src/engine/VertexArray.h
	src/engine/VertexBuffer.h
	src/engine/VertexBuffer.cpp
)

if(MSVC)
	target_link_libraries(engine
		SDL2 glew32 opengl32
	)
else()
	target_link_libraries(engine
		SDL2 GLU GLEW GL
	)
endif()

add_executable(game 
	src/game/AsteroidObject.cpp
	src/game/AsteroidObject.h 
	src/game/GameCollider.cpp
	src/game/GameCollider.h
	src/game/LaserObject.cpp
	src/game/LaserObject.h
	src/game/main.cpp
	src/game/PlayerController.cpp
	src/game/PlayerController.h
	src/game/PlayerObject.cpp
	src/game/PlayerObject.h
)

target_link_libraries(game engine)

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()