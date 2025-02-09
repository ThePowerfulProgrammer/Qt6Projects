cmake_minimum_required(VERSION 3.16)

project(Tic-Tac-Toe LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)


add_executable(Tic-Tac-Toe
  main.cpp
  mainwindow.h mainwindow.cpp
  positionrect.h positionrect.cpp
  stage.h stage.cpp
  images.qrc
  player.h player.cpp
)
target_link_libraries(Tic-Tac-Toe Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)


include(GNUInstallDirs)
install(TARGETS Tic-Tac-Toe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
