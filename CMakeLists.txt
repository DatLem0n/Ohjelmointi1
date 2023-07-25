cmake_minimum_required(VERSION 3.25)
project(Ohjelmointi1 C)

set(CMAKE_C_STANDARD 23)

add_executable(Ohjelmointi1 minitehtavat/minitehtavatViikko3.c minitehtavat/minitehtavatViikko4.c minitehtavat/main.c minitehtavat/minitehtavatViikko5.c minitehtavat/minitehtavatViikko6.c minitehtavat/minitehtavatViikko7.c minitehtavat/minitehtavatViikko8.c minitehtavat/minitehtavatViikko9.c minitehtavat/minitehtavatViikko10.c)
add_executable(Ohjelmointi1_KT3 kotitehtavat/kotitehtava3.c)
add_executable(Ohjelmointi1_KT4 kotitehtavat/kotitehtava4.c)
add_executable(Ohjelmointi1_KT5 kotitehtavat/kotitehtava5.c)
add_executable(Ohjelmointi1_KT6 kotitehtavat/kotitehtava6.c)

target_link_libraries(Ohjelmointi1 m)
