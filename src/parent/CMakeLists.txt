cmake_minimum_required(VERSION 3.10)

project(parent)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options system REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_EXECUTABLE( parent main.cpp )
target_link_libraries(parent PRIVATE Threads::Threads)

TARGET_LINK_LIBRARIES( parent LINK_PUBLIC ${Boost_LIBRARIES} )
