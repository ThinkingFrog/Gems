cmake_minimum_required(VERSION 3.15)
project(Gems)

include_directories(include)
file(GLOB_RECURSE SRC src/*.cpp)

# On Linux requires SFML to be installed to default dir
if (WIN32)
    set(SFML_DIR SFML/lib/cmake/SFML)
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)

add_executable(Gems ${SRC})

target_link_libraries(Gems sfml-graphics)

# For some reason runs on Linux with no need for dlls
if(WIN32)
    file(GLOB SFML_DLLS SFML/bin/*.dll)
    # Should copy dlls to executable directory
    file(COPY ${SFML_DLLS} DESTINATION Debug)
endif()