cmake_minimum_required(VERSION 3.0)

project(pmt LANGUAGES C)

add_executable(pmt main.c)

install(TARGETS pmt RUNTIME DESTINATION bin)
