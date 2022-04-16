cmake_minimum_required(VERSION 3.21)
project(CasinoGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(CasinoGame main.cpp Model/Game.h Utils/List.h Utils/ListElement.h Model/User.h Services/UserRepository.h)
