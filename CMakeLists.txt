cmake_minimum_required(VERSION 2.8)

project(person)

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

set(GTEST_INCLUDES ${SOURCE_DIR}/include)
set(GTEST_LIB ${BINARY_DIR}/libgtest.a)
set(GTEST_MAIN_LIB ${BINARY_DIR}/libgtest_main.a)

set(TEST_SOURCES tests/test_person.cpp)
include_directories(${GTEST_INCLUDES})

add_executable(person.test ${TEST_SOURCES})

find_package(Threads)
target_link_libraries(person.test
    ${GTEST_LIB}
    ${GTEST_MAIN_LIB}
    ${CMAKE_THREAD_LIBS_INIT}
)

enable_testing()
add_test(NAME pserson.test COMMAND person.test)
