cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(LuaIntegration VERSION 0.1.0 LANGUAGES CXX)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(LuaIntegration ${SOURCES})
target_include_directories(LuaIntegration PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(LuaIntegration -L${PROJECT_SOURCE_DIR}/lib -llua54)