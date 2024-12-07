cmake_minimum_required(VERSION 3.16)

project(ExamPrep LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql)

add_executable(ExamPrep
  main.cpp
  chocolate.h chocolate.cpp
  slab.h slab.cpp
  bar.h bar.cpp
  chocolatefactory.h chocolatefactory.cpp
  barfactory.h barfactory.cpp
  slabfactory.h slabfactory.cpp
  customer.h customer.cpp
)


target_link_libraries(ExamPrep Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS ExamPrep
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
