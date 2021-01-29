cmake_minimum_required(VERSION 3.0)

project(pmt LANGUAGES C)

aux_source_directory(. source_list)
add_executable(pmt main.c ${source_list})

install(TARGETS pmt RUNTIME DESTINATION bin)
