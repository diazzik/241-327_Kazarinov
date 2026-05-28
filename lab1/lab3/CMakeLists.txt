cmake_minimum_required(VERSION 3.16)

project(lab3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

qt_standard_project_setup()

qt_add_executable(lab3
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    restaurant.h

    httpclient.h
    httpclient.cpp

    restadapter.h
    restadapter.cpp
)

target_link_libraries(lab3 PRIVATE
    Qt6::Widgets
    Qt6::Network
)
