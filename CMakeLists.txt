cmake_minimum_required(VERSION 2.8)

project(QtSkeleton)

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
  add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
  add_definitions(-D_CRT_NON_CONFORMING_SWPRINTFS)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-DNOMINMAX)
  add_compile_options(/W4 /wd4481)
endif(MSVC)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall)
  add_compile_options(-Wextra)
  add_compile_options(-std=c++11)
endif()

cmake_policy(SET CMP0020 NEW) # Link to qtmain automatically

set(CMAKE_AUTOMOC ON) # Automatically MOC source files

if(NOT CMAKEVERSION VERSION_LESS 3.0)
  set(CMAKE_AUTOUIC ON) # Automatically UIC .ui files (CMake3+ only)
endif()

find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)

if(CMAKE_VERSION VERSION_LESS 3.0)
  qt5_wrap_ui(ui_files MainWindow.ui) # CMake2.8
else()
  set(ui_files MainWindow.ui) # CMake3+ only
endif()

qt5_add_resources(qrc_files QtSkeleton.qrc)

set(sources QtSkeleton.cpp MainWindow.cpp)

set(headers MainWindow.hpp)

if(WIN32)
  set(rc_files QtSkeleton.rc)
else()
  set(rc_files)
endif()

add_executable(QtSkeleton
  WIN32
  ${sources}
  ${headers}
  ${ui_files}
  ${qrc_files}
  ${rc_files})

target_include_directories(QtSkeleton PUBLIC "${CMAKE_CURRENT_BINARY_DIR}") # Needed to include .h files generated from .ui

target_link_libraries(QtSkeleton Qt5::Core Qt5::Gui Qt5::Widgets)
