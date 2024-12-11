cmake_minimum_required(VERSION 3.29)
project(course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/egortomasev/Qt/6.8.0/macos")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(course main.cpp
        StartWindow.cpp
        StartWindow.h
        StartWindow.ui
        clases.h
        clases.cpp
        passengerregwindow.cpp
        passengerregwindow.h
        passengerregwindow.ui
        logindialog.cpp
        logindialog.h
        logindialog.ui
        passengerarrivedflightsadddialog.cpp
        passengerarrivedflightsadddialog.h
        passengerflightsadddialog.ui
        passengerdepartedflightsadddialog.cpp
        passengerdepartedflightsadddialog.h
        passengerdepartedflightsadddialog.ui
        regestrationdialog.cpp
        regestrationdialog.h
        regestrationdialog.ui
        pilotsregdialog.cpp
        pilotsregdialog.h
        pilotsregdialog.ui
        crewregdialog.cpp
        crewregdialog.h
        crewregdialog.ui
        cargodialog.cpp
        cargodialog.h
        cargodialog.ui
        cargoarrivedflightsadddialog.cpp
        cargoarrivedflightsadddialog.h
        cargoarrivedflightsadddialog.ui
        departedcargoflightsadddialog.cpp
        departedcargoflightsadddialog.h
        departedcargoflightsadddialog.ui
        Exception.cpp
        Exception.h
)
target_link_libraries(course
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

