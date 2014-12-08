cmake_minimum_required(VERSION 3.0)

project(person CXX)

add_definitions(-Wall)
add_definitions(-std=c++11)

include_directories(src)


# Get GTEST framework
include(ExternalProject)

ExternalProject_Add(
    gtest_project
    SVN_REPOSITORY  http://googletest.googlecode.com/svn/trunk/
    PREFIX gtest
    INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest_project SOURCE_DIR BINARY_DIR DOWNLOAD_DIR)

add_library(gtest STATIC IMPORTED)

set_property(
    TARGET gtest
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES
    ${SOURCE_DIR}/include
)

set_property(
    TARGET gtest 
    PROPERTY IMPORTED_LOCATION 
    ${BINARY_DIR}/libgtest.a
)
set_property(
    TARGET gtest 
    PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES 
    ${BINARY_DIR}/libgtest_main.a
)


set(TEST_SOURCES tests/test_person.cpp)

add_executable(person.test ${TEST_SOURCES})

target_link_libraries(person.test gtest)

enable_testing()
add_test(NAME pserson.test COMMAND person.test)
