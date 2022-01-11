cmake_minimum_required(VERSION 3.5)

project(ConvertingTable)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include_directories(./Headers)

set(HEADERS 
    ./Headers/AbstractVersion.hpp
    ./Headers/FirstVersion.hpp
    ./Headers/SecondVersion.hpp
    ./Headers/GeneratorTasks.hpp)

set(SOURCES 
    ./Sources/AbstractVersion.cpp
    ./Sources/FirstVersion.cpp
    ./Sources/SecondVersion.cpp
    ./Sources/GeneratorTasks.cpp
    ./Sources/main.cpp)


add_executable(ConvertingTable ${SOURCES} ${HEADERS})

set_target_properties(
    ConvertingTable PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
