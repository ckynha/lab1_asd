project(lab1-asd)
cmake_minimum_required(VERSION 3.12)   
option(BUILD_TESTS "Build test" ON)

add_executable(main main.cpp generator.cpp generator.h catch.hpp) # ����������� main.exe

if(BUILD_TESTS)
  enable_testing()
  add_executable(test1 test.cpp generator.cpp generator.h catch.hpp) # ����������� test1.exe
  add_test(test1 test1) # ��������� test1.exe ��� �������� ���������. ���� �������, ���� ��� ���������� ��� 0.
endif()
