cmake_minimum_required(VERSION 3.16)

project(ExamPreperation LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Xml)

add_executable(ExamPreperation
  main.cpp
  person.h person.cpp
  product.h product.cpp
  chocolate.h chocolate.cpp
  scan.h scan.cpp
  rainfall.h rainfall.cpp
  staff.h staff.cpp
  staffmanager.h staffmanager.cpp
)
target_link_libraries(ExamPreperation Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Xml)

include(GNUInstallDirs)
install(TARGETS ExamPreperation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
