cmake_minimum_required(VERSION 3.15)
project(Gems)

include_directories(include)
file(GLOB SRC src/*cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR SFML/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(Gems ${SRC})

target_link_libraries(Gems sfml-graphics)