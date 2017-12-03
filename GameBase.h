#pragma once

#include "stdafx.h"
#include <iostream>
#include<vector>
#include <string>

using namespace std;

class GameBase {
protected:
	//member variables
	string player;
	 int width;
	 int height;
	int turnCount = 0;
	vector<vector<string>> board; 
	//length of the longest string 
	int longest = 1;

	//functions 
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	int prompt(unsigned int & a, unsigned int & b);

public:
	static GameBase* createGame(int argc, char *argv[]);
	int play();
};


