// lab2.cpp : Defines the entry point for the console application. Defines the TicTacToe game and executes it. 
//
#include "stdafx.h"
#include "lab3Header.h"
#include "GameBase.h"
#include "TicTacToeGame.h"
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//overload operator to print of type TicTacToe
ostream& operator<<(ostream & os, const TicTacToeGame & game) {

	for (int i = game.height - 1; i >= 0; i--) {
		for (int j = 0; j <= game.width; j++) {
			if (j == 0) {
				os << i+1 << setw(game.longest + 2);
			}
			else {
				//subtract the total distance by character distance 
				os << game.board.at(i).at(j-1) << setw(game.longest + 2) << " ";
			}
		}
		os << endl << endl;
	}

	cout << setw(game.longest);
	for (int i = 0; i < game.width; i++) {
		cout << setw(game.longest + 3) << i+1 << setw(game.longest + 2);
	}
	cout << endl;
	return os;
}

//Checks if the game was won 
bool TicTacToeGame::done() {
	if ((board.at(0).at(0) == board.at(1).at(1) && board.at(1).at(1) == board.at(2).at(2)) && board.at(0).at(0) != " ") {
		return true;
	}

	if (board.at(0).at(2) != " " && (board.at(0).at(2) == board.at(1).at(1) && board.at(1).at(1) == board.at(2).at(0))) {
		return true;
	}

	for (int i = 0; i < width; i++) {
		if (board.at(i).at(0) == board.at(i).at(1) && board.at(i).at(1) == board.at(i).at(2) && board.at(i).at(0) != " ") {
			return true;
		}
		if (board.at(0).at(i) == board.at(1).at(i) && board.at(1).at(i) == board.at(2).at(i) && board.at(0).at(i) != " ") {
			return true;
		}
	}

	return false;

}

//Checks if the game ended in a draw. If any of the positions in the board contain the null character 
bool TicTacToeGame::draw() {
	cout << *this << endl;
	if (done()) {
		return true;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board.at(i).at(j) == " ") {
				return false;
			}
		}
	}

	return true;
}


int TicTacToeGame::turn() {
	//changes turn of player
	if (player == "O") {
		player = 'X';
	}
	else {
		player = "O";
	}

	cout << "Player " << player << "'s turn" << endl;
	unsigned int x;
	unsigned int y;

	int result = prompt(x, y);
	if (result == quit) {
		return quit;
	}

	//checks whether the input values are within the game board. If not, then reprompts the user. 
	while (board.at(x-1).at(y-1) != " " || x < 1 || x > 3 || y < 1 || y > 3) {
		result = prompt(x, y);
		if (result == quit) {
			return quit;
		}
	}

	//assigns the player character into the array
	board.at(x-1).at(y-1) = player;
	if (player.length() > longest) {
		longest = player.length();
	}
	//increment number of turns for printing purposes at the end
	turnCount += 1;
	return success;

}
