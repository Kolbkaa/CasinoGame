cmake_minimum_required(VERSION 3.21)
project(CasinoGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(CasinoGame main.cpp Model/Game.cpp Model/Game.h Services/GameList.cpp Services/GameList.h Model/GameListElement.cpp Model/GameListElement.h)
