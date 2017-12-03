// lab2.cpp : Defines the entry point for the console application. Defines the TicTacToe game and executes it. 
//
#include "stdafx.h"
#include "lab3Header.h"
#include "GameBase.h"
#include "GomokuGame.h"
#include "TicTacToeGame.h"
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


int main(int argc, char *argv[])
{
	GameBase* newGame = GameBase::createGame(argc, argv); 
	if (newGame == 0) {
		//call usage function instructing the user how to call the program. Return the value of usage
		return usage(argv[programName], "TicTacToe or Gomoku (optionally enter a dimension size and number of consecutive pieces to win seperated by spaces)");
	}

	return (*newGame).play(); 

}

