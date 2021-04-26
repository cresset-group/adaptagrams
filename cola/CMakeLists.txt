project(adaptagrams_project)
cmake_minimum_required(VERSION 3.4)
include(GenerateExportHeader)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DNOMINMAX)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# libvpsc
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/libvpsc VPSC_SOURCES)
add_library(vpsc SHARED ${VPSC_SOURCES})
target_include_directories(vpsc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})
# Needed for the Rectangle::xBorder and Rectangle::yBorder global data.
generate_export_header(vpsc)

# libcola
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/libcola COLA_SOURCES)
add_library(cola SHARED ${COLA_SOURCES})
target_include_directories(cola PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# libavoid

add_definitions(-DLIBAVOID_EXPORTS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/libavoid AVOID_SOURCES)
add_library(avoid SHARED ${AVOID_SOURCES})
target_include_directories(avoid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cola vpsc)
target_link_libraries(avoid vpsc)
