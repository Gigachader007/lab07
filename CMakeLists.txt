cmake_minimum_required(VERSION 3.31)
#CMake 3.31 and above prefer the ENCODING default to be UTF-8 .

project(lab07)


file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME})