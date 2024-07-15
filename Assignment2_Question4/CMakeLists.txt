cmake_minimum_required(VERSION 3.14)

project(Assignment2_Question4 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Xml)

add_executable(Assignment2_Question4
    main.cpp
    person.h person.cpp
    registration.h registration.cpp
    studentregistration.h studentregistration.cpp
    guestregistration.h guestregistration.cpp
    registrationlist.h registrationlist.cpp
    registrationdialog.h registrationdialog.cpp
    registrationlistwriter.h registrationlistwriter.cpp
    registrationlistreader.h registrationlistreader.cpp
    registrationfactory.h registrationfactory.cpp
    abstractregistrationfactory.h abstractregistrationfactory.cpp
)

target_link_libraries(Assignment2_Question4 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Xml)

include(GNUInstallDirs)
install(TARGETS Assignment2_Question4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
