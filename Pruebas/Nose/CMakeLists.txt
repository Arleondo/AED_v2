cmake_minimum_required(VERSION 3.28)
project(Nose)

set(CMAKE_CXX_STANDARD 17)

# Agregar GLFW
add_subdirectory(GLFW/glfw-3.4)

# Incluir headers
include_directories(GLFW/glfw-3.4/include)

add_executable(Nose main.cpp)

# Luego vincular las librerías
target_link_libraries(Nose glfw ${CMAKE_DL_LIBS})
target_link_libraries(Nose glfw opengl32 ${CMAKE_DL_LIBS})