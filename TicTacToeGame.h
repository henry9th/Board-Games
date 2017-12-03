#pragma once
// lab2.cpp : Defines the entry point for the console application. Defines the TicTacToe game and executes it. 
//
#include "stdafx.h"
#include "lab3Header.h"
#include "GameBase.h"
#include <iostream>
#include<vector>
#include <string>
#include <iomanip>
using namespace std;

class TicTacToeGame : public GameBase {

public:
	TicTacToeGame() {
		player = "O";
		width = 3;
		height = 3;
		for (int i = 0; i < height; i++) {
			vector<string> row; 
			for (int i = 0; i < width; i++) {
				row.push_back(" "); 
			}
			board.push_back(row);
		}
	}

	void print() { cout << *this; }
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	int area() { return width*height; }
	friend ostream& operator<<(ostream & os, const TicTacToeGame & game);
};

