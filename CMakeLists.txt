cmake_minimum_required(VERSION 3.10)

project(GLPlayground)
file(GLOB SourceFiles "src/*.cc")

add_executable(GLPlayground 
                ${SourceFiles}
                include/glad/glad.c)

# Cocoa, OpenGL and IOKit

find_library(COCOA Cocoa)
find_library(OPENGL OpenGL)
find_library(IOKIT IOKit)

target_include_directories(GLPlayground PUBLIC include/ src/include/)
target_link_directories(GLPlayground PUBLIC lib/)
target_link_libraries(GLPlayground PUBLIC glfw3 ${COCOA} ${OPENGL} ${IOKIT})