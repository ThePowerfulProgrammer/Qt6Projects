cmake_minimum_required(VERSION 3.14)

project(Assignment2_Question1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(Assignment2_Question1
  main.cpp
  person.h person.cpp
  registration.h registration.cpp
  studentregistration.h studentregistration.cpp
  guestregistration.h guestregistration.cpp
  registrationlist.h registrationlist.cpp
  registrationdialog.h registrationdialog.cpp
)
target_link_libraries(Assignment2_Question1 Qt${QT_VERSION_MAJOR}::Core  Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS Assignment2_Question1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
