cmake_minimum_required(VERSION 3.3)
project(numeths)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BisectionMethod.cpp BisectionMethod.h RootFindingMethod.cpp RootFindingMethod.h Iteration.cpp Iteration.h RegulaFalsiMethod.cpp RegulaFalsiMethod.h)

include_directories( ${BOOST_ROOT} )

#### Building static library.
add_library(numeths ${SOURCE_FILES})

#### Building demo for the library.
add_executable(numeths_demo main.cpp)
target_link_libraries(numeths_demo ${CMAKE_SOURCE_DIR}/bin/Debug/libnumeths.a)