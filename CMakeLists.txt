cmake_minimum_required(VERSION 3.29)
project(algorithms)
set(CMAKE_CXX_STANDARD 20)

# Headers are found automatically via #include — only .cpp files needed here
add_executable(algorithms
        main.cpp
        rod_cutting.cpp
        graph/knight_steps.cpp
        exam/supertriangle.h
)