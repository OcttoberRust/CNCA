cmake_minimum_required(VERSION 3.16)
project(CNCA_1)

set(CMAKE_CXX_STANDARD 17)


include_directories(/usr/local/Cellar/boost/1.72.0_2/include)
include_directories(/usr/local/Cellar/boost/1.72.0_2/lib)

set(SOURCE_FILES main.cpp Server.cpp Server.h Message.cpp Message.h Client.cpp Client.h)


add_executable(CNCA ${SOURCE_FILES})
target_link_options(CNCA INTERFACE "-I /usr/local/Cellar/boost/1.72.0_2 -lboost_thread -lpthread main.cpp")

find_package(Boost 1.72.0 COMPONENTS system filesystem thread chrono date_time REQUIRED)

target_link_libraries(CNCA ${Boost_LIBRARIES})
