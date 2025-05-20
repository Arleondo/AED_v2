cmake_minimum_required(VERSION 3.28)
project(Graficadora)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(GLFW/glfw-3.4)

include_directories(GLFW/glfw-3.4/include)

add_executable(Graficadora main.cpp)

target_link_libraries(Graficadora glfw ${CMAKE_DL_LIBS})