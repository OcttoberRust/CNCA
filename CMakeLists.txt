cmake_minimum_required(VERSION 3.16)
project(CNCA)

set(CMAKE_CXX_STANDARD 20)

add_executable(CNCA main.cpp server.cpp server.h client.cpp client.h message.cpp message.h)
set(GCC_COVERAGE_COMPILE_FLAGS "-O3 -DNDEBUG -DBOOST_UBLAS_NDEBUG")
find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})