cmake_minimum_required(VERSION 3.27)
project(TimeTraveller)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})


set(SDL2_PATH "./SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(imgui)

#set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/SDL2_image/x86_64-w64-mingw32")

set(SDL2_IMAGE_PATH "SDL2_image/x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

file(COPY ${SDL2_PATH}/bin/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${SDL2_PATH}/bin/libwinpthread-1.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${SDL2_IMAGE_PATH}/bin/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})



find_package(spdlog CONFIG REQUIRED)

include_directories(ECS)
add_executable(TimeTraveller
        main.cpp
        imgui/imgui_impl_sdlrenderer2.cpp
        imgui/imgui_impl_sdl2.cpp
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        Game.cpp
        Game.h
        Game.h
        TextureManager.cpp
        TextureManager.h
        GameObject.cpp
        GameObject.h
        Map.cpp
        Map.h
        ECS/ECS.h
        ECS/Components.h
        ECS/TransformComponent.h
        ECS/SpriteComponent.h
        ECS/Vector2D.h
        ECS/Vector2D.cpp
        ECS/KeyboardController.h
        ECS/ColliderComponent.h
        Collision.cpp
        Collision.h
        ECS/TileComponent.h
        ECS/ECS.cpp
        ECS/Animation.cpp
        ECS/Animation.h
        MainMenu.cpp
        MainMenu.h
        AssetManager.cpp
        AssetManager.h
        ECS/ProjectileComponent.cpp
        ECS/ProjectileComponent.h
        logger.cpp
        logger.h


)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        spdlog::spdlog
         -static-libgcc -static-libstdc++
)

