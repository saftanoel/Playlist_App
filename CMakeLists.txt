cmake_minimum_required(VERSION 3.5)

project(Lab11 VERSION 0.1 LANGUAGES CXX)

# Set up automatic handling of UIC, MOC, and RCC files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Debug message to check the Qt version being used
message(STATUS "Using Qt version: ${QT_VERSION_MAJOR}")

# Define the project sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    song.h
    song.cpp
    songcontroller.h
    songcontroller.cpp
)

# Include the current source directory for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Conditional handling based on Qt version
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Lab11
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(Lab11
        ${PROJECT_SOURCES}
    )
endif()

# Link the Qt Widgets library
target_link_libraries(Lab11 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Set properties for macOS bundle if applicable
if(APPLE)
    if(${QT_VERSION} VERSION_LESS 6.1.0)
        set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Lab11)
    endif()
    set_target_properties(Lab11 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )
else()
    set_target_properties(Lab11 PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

# Define the installation paths
include(GNUInstallDirs)
install(TARGETS Lab11
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize executable for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Lab11)
endif()
