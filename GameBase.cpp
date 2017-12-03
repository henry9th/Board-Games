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

//Prompts the user for an input and gets the line, checks if its in the correct format, and change the value of a and b by the passed reference
int GameBase::prompt(unsigned int & a, unsigned int & b) {
	cout << "Enter valid coordinate in format 'x,y' or 'quit'" << endl;
	string input;
	getline(cin, input);

	if (input == "quit") {
		return quit;
	}

	//checks if the line only contains digits and ,
	if (input.find_first_not_of("0123456789, ") != string::npos) {
		return prompt(a, b);
	}

	//replaces the comma with a space
	input[input.find(",")] = ' ';

	istringstream is(input);
	if (is >> b) {
		if (is >> a) {
			if (a > width || a <= 0 || b > height || b <= 0) {
				return prompt(a, b);
			}
			return success; //if both values were extracted
		}
		else {
			return prompt(a, b);
		}
	}
	else {
		return prompt(a, b);
	}
	return prompt(a, b);
}

int GameBase::play() {
	cout << endl;
	print();
	int var = 0;

	//var keeps track of which of the three ways the game terminated
	while (var == 0) {
		//If the user decided to quit the game
		if (turn() == quit) {
			var = 3;
		}
		//if one player won
		else if (done() == true) {
			var = 1;
		}
		//if the game had no more turns without a winner
		else if (draw() == true) {
			var = 2;
		}
	}

	//cout << *this << endl;

	if (var == 3) {
		cout << "Player " << player << " quit the game. Number of turns: " << turnCount << endl;
		return quit;
	}
	if (var == 1) {
		print();
		cout << "Player " << player << " wins!" << endl;
		return success;
	}
	if (var == 2) {
		print();
		cout << "The game is a draw and no winning moves remain. Number of turns: " << turnCount << endl;
		return no_more_turns;
	}

	return success;

}

GameBase* GameBase::createGame(int argc, char *argv[]) {
	//check if only one argument was passed. Should not exceed 2 which is denoted by numMaxCmdLines
	if (argc == numCmdLines) {
		if (string(argv[1]) == "TicTacToe") {
			TicTacToeGame* newGame = new TicTacToeGame();
			return newGame;
		}
		if (string(argv[1]) == "Gomoku") {
			GomokuGame* newGame = new GomokuGame(19, 19, 5);
			return newGame;
		}
	}

	if (argc == numCmdLines + 1) {
		if (string(argv[1]) == "Gomoku") {
			int num = atoi(argv[2]);
			if (num > 0) {
				if (num < 5) {
					GomokuGame* newGame = new GomokuGame(num, num, num);
					return newGame;
				}
				GomokuGame* newGame = new GomokuGame(num, num, 5);
				return newGame;
			}
			else {
				cout << "Dimension value cannot be less 1" << endl; 
				return 0; 
			}
		} 

	}

	if (argc == numCmdLines + 2) {
		if (string(argv[1]) == "Gomoku") {
			int num = atoi(argv[2]);
			int num2 = atoi(argv[3]); 
			if (num > 0) {
				if (num2 > 0) {
					GomokuGame* newGame = new GomokuGame(num, num, num2);
					return newGame;
				}
				else {
					cout << "Consecutive Piece value cannot be less 1" << endl;
					return 0; 
				}
			}
			else {
				cout << "Dimension value cannot be less 1" << endl;

				return 0;
			}
		}
	}

	return 0;
}


