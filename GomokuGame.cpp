// lab2.cpp : Defines the entry point for the console application. Defines the TicTacToe game and executes it. 
//
#include "stdafx.h"
#include "lab3Header.h"
#include "GameBase.h"
#include "GomokuGame.h"
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//overload operator to print of type GomokuGame
ostream& operator<<(ostream & os, const GomokuGame & game) {
	os << endl;
	for (int i = game.height; i > 0; i--) {
		for (int j = 0; j < game.width; j++) {
			if (j == 0) {
				os << i << setw(game.longest + 2) << game.board.at(i-1).at(j) << setw(game.longest + 2) ;
			}
			else { 
				if (j == game.width - 1) {
					os << game.board.at(i - 1).at(j);
				}
				else {
					os << game.board.at(i - 1).at(j) << setw(game.longest + 2);
				}
			}
		}
		os << endl;
	}

	os << setw(game.longest + 3);
	for (int i = 0; i < game.width; i++) {

		os << i+1 << setw(game.longest + 2);
	}
	os << endl;
	return os;
}


bool GomokuGame::done() {

	//CHECK HORIZONTALLY
	int count = 0; 
	string previous; 
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board.at(i).at(j) == previous && previous != " ") {
				count += 1; 
				if (count == num) {
					return true; 
				}
			}
			else {
				previous = board.at(i).at(j);
				count = 1; 
			}

		}
	}

	//CHECK VERTICALLY
	count = 0; 
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board.at(j).at(i) == previous && previous != " ") {
				count += 1;
				if (count == num) {
					return true;
				}
			}
			else {
				previous = board.at(j).at(i);
				count = 1;
			}

		}
	} 

	//CHECK DIAGONALLY
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			count = 0; 
			int a = j; 
			int b = i; 
			while (a < width && b < height) {
				if (board.at(a).at(b) == previous && previous != " ") {
					count += 1;
					a += 1; 
					b += 1; 
					if (count == num) {
						return true;
					}
				}
				else {
					previous = board.at(a).at(b);
					count = 1;
					a += 1;
					b += 1;
				}

			}


		}
	}


	for (int i = height-1; i >= 0; i--) {
		for (int j = width-1; j >= 0; j--) {
			count = 0;
			int a = j;
			int b = i;
			while (a < width && b > 0) {
				if (board.at(a).at(b) == previous && previous != " ") {
					count += 1;
					a += 1;
					b -= 1;
					if (count == num) {
						return true;
					}
				}
				else {
					previous = board.at(a).at(b);
					count = 1;
					a += 1;
					b -= 1;
				}

			}


		}
	}

	return false;

}

bool GomokuGame::draw() {
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


int GomokuGame::turn() {
	//changes turn of player
	if (player == "B") {
		player = "W";
	}
	else {
		player = "B";
	}

	cout << "Player " << player << "'s turn" << endl;
	unsigned int x;
	unsigned int y;

	int result = prompt(x, y);
	if (result == quit) {
		return quit;
	}

	//checks whether the input values are within the game board. If not, then reprompts the user. 
	while (board.at(x - 1).at(y - 1) != " " || x < 1 || x > width || y < 1 || y > height) {
		result = prompt(x, y);
		if (result == quit) {
			return quit;
		}
	}

	//assigns the player character into the array
	board.at(x - 1).at(y - 1) = player;
	if (player.length() > longest) {
		longest = player.length();
	}
	//increment number of turns for printing purposes at the end
	turnCount += 1;
	return success;

}

