cmake_minimum_required(VERSION 3.18)

project(LIBVCT LANGUAGES C)
set(ROOT_DIR "${PROJECT_SOURCE_DIR}")

# Define the version string
set(LIBVCT_API_VERSION_STRING "3.0.1" CACHE STRING "LibVCT version" FORCE)


include(${ROOT_DIR}/cmake/common.cmake NO_POLICY_SCOPE)

#
# Extract the pieces of the version info from the version string above
DISSECT_VERSION()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libvct_api_conf.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/libvct_api_conf.h)

option(LIBVCT_BUILD_WITH_SHAPELIB "Enable support Esri shapelib" OFF)
option(LIBVCT_BUILD_WITH_FILEGDB "Enable support Esri FileGDB" OFF)
option(LIBVCT_BUILD_WITH_SPATIALITE "Enable support GDAL Spatialite" OFF)

set(LIBVCT_SRC 
    vct_reader.c
    vct_writer.c)
set(LIBVCT_LINK 
    ${LIBVCT_LINK})

if(LIBVCT_BUILD_WITH_SHAPELIB)
set(LIBVCT_SRC 
    ${LIBVCT_SRC}
    vct_shapelib.c)
set(LIBVCT_LINK 
    ${LIBVCT_LINK}
    shapelib)
endif()

if(LIBVCT_BUILD_WITH_FILEGDB)
set(LIBVCT_SRC 
    ${LIBVCT_SRC}
    vct_filegdb.c)
set(LIBVCT_LINK 
    ${LIBVCT_LINK}
    filegdb)
endif()

if(LIBVCT_BUILD_WITH_SPATIALITE)
set(LIBVCT_SRC 
    ${LIBVCT_SRC}
    vct_spatialite.c)
set(LIBVCT_LINK 
    ${LIBVCT_LINK}
    spatialite)
endif()

add_library(LibVCT STATIC ${LIBVCT_SRC})