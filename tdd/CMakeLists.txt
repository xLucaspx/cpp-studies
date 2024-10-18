cmake_minimum_required(VERSION 3.28)
project(tdd)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(tdd
		src/main.cpp
		src/Auction.cpp
		src/Auction.hpp
		src/Bid.cpp
		src/Bid.hpp
		src/Evaluator.cpp
		src/Evaluator.hpp
		src/User.cpp
		src/User.hpp
)

include_directories(tests)
Include(FetchContent)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG v3.7.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(tdd-test
		tests/auction-test.cpp
		tests/evaluator-test.cpp
		tests/user-test.cpp
		src/Auction.cpp
		src/Auction.hpp
		src/Bid.cpp
		src/Bid.hpp
		src/Evaluator.cpp
		src/Evaluator.hpp
		src/User.cpp
		src/User.hpp
)

target_link_libraries(tdd-test PRIVATE Catch2::Catch2WithMain)
