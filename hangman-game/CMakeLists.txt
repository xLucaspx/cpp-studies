cmake_minimum_required(VERSION 3.28)
project(hangman_game)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(hangman_game
		file.cpp
		file.hpp
		hangman.cpp
		hangman.hpp
		main.cpp
		out.cpp
		out.hpp
		app.cpp)
