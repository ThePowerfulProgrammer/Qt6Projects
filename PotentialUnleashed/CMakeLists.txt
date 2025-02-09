cmake_minimum_required(VERSION 3.16)

project(PotentialUnleashed LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Sql)

add_executable(PotentialUnleashed
  main.cpp
  mainwindow.h mainwindow.cpp
  exercise.h exercise.cpp
  createworkoutdialog.h createworkoutdialog.cpp
  workout.h workout.cpp
  utlity.h utlity.cpp

)
target_link_libraries(PotentialUnleashed Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS PotentialUnleashed
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
