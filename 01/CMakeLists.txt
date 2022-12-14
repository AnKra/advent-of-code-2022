cmake_minimum_required(VERSION 3.20)

project(day01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# generate executable
add_executable(${PROJECT_NAME} 
    src/main.cpp 
)

target_include_directories (${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../common/include
)

target_compile_options(${PROJECT_NAME}  PRIVATE -Werror -Wall -Wextra)

# test
enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}_test
  test/test.cpp
)

target_include_directories (${PROJECT_NAME}_test
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../common/include
)

target_link_libraries(${PROJECT_NAME}_test
  GTest::gtest
  GTest::gtest_main
)
gtest_discover_tests(${PROJECT_NAME}_test)
