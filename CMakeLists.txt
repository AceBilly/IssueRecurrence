cmake_minimum_required(VERSION 3.10)

project(Issue)


aux_source_directory(src/ OC_SRC)


add_executable(Issue ${OC_SRC})

target_link_libraries(Issue pistache crypto ssl pthread dl)
