cmake_minimum_required(VERSION 3.16)

project(SnakePlusPlus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies: Raylib
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # Try to find Raylib installed on the system

# If Raylib is not found, fetch and build it
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Disable Raylib's examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# Add executable
add_executable(SnakePlusPlus
  main.cpp
  snake.h snake.cpp
  food.h food.cpp
  mathutility.h mathutility.cpp
)

# Link libraries
target_link_libraries(SnakePlusPlus raylib)

# Install rules
include(GNUInstallDirs)
install(TARGETS SnakePlusPlus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
