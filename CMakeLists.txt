cmake_minimum_required(VERSION 3.15)
project(Gems)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB SRC src/*cpp)

if (WIN32)
    set(SFML_DIR SFML/lib/cmake/SFML)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(Gems ${SRC})

target_link_libraries(Gems sfml-graphics)