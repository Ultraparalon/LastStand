CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(last_stand)

file(GLOB SOURCES sources/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(includes)

find_package(SFML 2.5 REQUIRED system window
  graphics network audio)

target_link_libraries(${PROJECT_NAME} sfml-system
  sfml-window sfml-graphics sfml-network sfml-audio)
