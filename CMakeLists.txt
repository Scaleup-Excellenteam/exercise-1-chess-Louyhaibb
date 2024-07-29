cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess
        eexercise-1-chess-Louyhaibb/Chess/src/Chess.cpp
        exercise-1-chess-Louyhaibb/Chess/src/main.cpp
        exercise-1-chess-Louyhaibb/Chess/src/GameLogic.cpp
        exercise-1-chess-Louyhaibb/Chess/include/GameLogic.h
        exercise-1-chess-Louyhaibb/Chess/src/Pawn.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Pawn.h
        exercise-1-chess-Louyhaibb/Chess/src/Bishop.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Bishop.h
        exercise-1-chess-Louyhaibb/Chess/src/Knight.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Knight.h
        exercise-1-chess-Louyhaibb/Chess/src/Piece.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Piece.h
        exercise-1-chess-Louyhaibb/Chess/src/Rock.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Rock.h
        exercise-1-chess-Louyhaibb/Chess/src/Queen.cpp
        exercise-1-chess-Louyhaibb/Chess/include/Queen.h
        exercise-1-chess-Louyhaibb/Chess/src/King.cpp
        exercise-1-chess-Louyhaibb/Chess/include/King.h
)
