cmake_minimum_required(VERSION 3.25)
project(Sklep_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sklep_cpp main.cpp klient.cpp klient.h zamowienie.cpp zamowienie.h produkt.cpp produkt.h sklep.cpp sklep.h xd.cpp xd.h)
