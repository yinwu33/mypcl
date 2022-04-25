find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_LINKED_LIBS ${GTEST_BOTH_LIBRARIES} pthread Eigen3::Eigen mypcl)

add_executable(test_bst test_bst.cpp)
target_link_libraries(test_bst ${TEST_LINKED_LIBS})
gtest_discover_tests(test_bst)


add_executable(test_io test_io.cpp)
target_link_libraries(test_io ${TEST_LINKED_LIBS})
gtest_discover_tests(test_io)

add_executable(test_pca test_pca.cpp)
target_link_libraries(test_pca ${TEST_LINKED_LIBS})
gtest_discover_tests(test_pca)