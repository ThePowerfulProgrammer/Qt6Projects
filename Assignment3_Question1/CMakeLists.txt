cmake_minimum_required(VERSION 3.16)

project(Assignment3_Question1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Xml)

add_executable(Assignment3_Question1
  main.cpp
  book.h book.cpp
  bookwriter.h bookwriter.cpp
  bookinput.h bookinput.cpp
)
target_link_libraries(Assignment3_Question1 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Xml)

include(GNUInstallDirs)
install(TARGETS Assignment3_Question1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
