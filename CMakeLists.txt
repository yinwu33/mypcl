cmake_minimum_required(VERSION 3.8)
project(mypcl)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

enable_testing()

find_package(Eigen3 REQUIRED)

set(LIB_SOURCE  src/pca.cpp
                src/io.cpp
                src/types/cloud.cpp
                src/bstree.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} ${LIB_SOURCE})
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)

add_subdirectory(${PROJECT_SOURCE_DIR}/test)