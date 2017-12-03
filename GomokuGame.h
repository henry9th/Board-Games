// lab2.cpp : Defines the entry point for the console application. Defines the TicTacToe game and executes it. 
//
#include "stdafx.h"
#include "lab3Header.h"
#include "GameBase.h"
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class GomokuGame : public GameBase {
public:
	GomokuGame(int x, int y, int numPieces) {
		num = numPieces;
		player = "B";
		width = x;
		height = y;
		for (int i = 0; i < height; i++) {
			vector<string> row;
			for (int i = 0; i < width; i++) {
				row.push_back(" ");
			}
			board.push_back(row);
		}
	}
	int num; 
	friend ostream& operator<<(ostream & os, const GomokuGame & game);
	void print() { cout << *this; }
	virtual bool draw();
	virtual bool done();
	virtual int turn();

};
