cmake_minimum_required(VERSION 3.15)

project(Chess)

# Define the executable target and specify the sources for the target
add_executable(Chess
		../src/main.cpp
		../src/Chess.cpp
		../src/Bishop.cpp
		../src/GameLogic.cpp
		../src/King.cpp
		../src/Knight.cpp
		../src/Pawn.cpp
		../src/Piece.cpp
		../src/Queen.cpp
		../src/Rook.cpp
)

# Set the C++ standard
if (MSVC AND CMAKE_VERSION VERSION_GREATER_EQUAL 3.21)
	set(CMAKE_CXX_STANDARD 23)
else()
	set(CMAKE_CXX_STANDARD 20)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compile options for MSVC
if (MSVC)
	add_compile_options(/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif()

# Add subdirectories (if they contain their own CMakeLists.txt)
add_subdirectory(include)
add_subdirectory(src)

