cmake_minimum_required(VERSION 3.20)
project(cppProj CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -g)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fsanitize=address,undefined")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include(FetchContent)
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.11)
FetchContent_MakeAvailable(doctest)

add_executable(playground src/main.cpp)
target_include_directories(playground PRIVATE include)

foreach(name vec list)
  add_executable(test_${name} tests/test_${name}.cpp)
  target_include_directories(test_${name} PRIVATE include)
  target_link_libraries(test_${name} PRIVATE doctest::doctest)
  add_test(NAME ${name} COMMAND test_${name})
endforeach()

enable_testing()