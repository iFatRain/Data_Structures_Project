cmake_minimum_required(VERSION 3.10)
project(Data_Structures_Project)

set(CMAKE_CXX_STANDARD 11)

include_directories(main)
include_directories(main/nodeClass)
include_directories(main/TaskClass)

add_executable(Data_Structures_Project
    main/nodeClass/node.cpp
    main/nodeClass/node.hpp
    main/TaskClass/Task.cpp
    main/TaskClass/Task.hpp
    main/helperFunctions.cpp
    main/helperFunctions.hpp
    main/main.cpp
    main/main.h
    main/RTOS.cpp
    main/RTOS.hpp)
