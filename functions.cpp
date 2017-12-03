#include "stdafx.h"
#include "lab3Header.h"
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//The usage message function should print out the program name and how to run the program using those parameters
//Takes in two strings: one giving the name of the program and another string parameter giving the rest of the information to convey to the user
int usage(char * programName, string message) {
	std::cout << programName << " " << message << std::endl;
	return wrong_number_command_lines;
}

int parseFromFile(vector<string> & reference, char * fileName) {
	//new input file stream 
	ifstream ifs;
	ifs.open(fileName);

	if (ifs.is_open()) {
		string i;
		while (ifs >> i) {
			if (i != "") {
				try {
					reference.push_back(i);
				}
				catch (...) {
					return failure_to_push_back;
				}
			}
		}
	}

	else {
		cout << "error, not open" << endl;
		return file_stream_not_open;
	}
	return success;
}

int iterateStringVector(vector<int> integers, vector<string> fileOutput) {

	for (size_t s = 0; s < fileOutput.size(); s++) {
		string outputLine = fileOutput[s];
		int convertedInt;
		unsigned int count = 0;
		for (size_t t = 0; t < outputLine.size(); t++) {
			if (isdigit(outputLine[t])) {
				count++;
			}
		}

		//if the number of characters equals the number of digits
		if (count == outputLine.size()) {
			//new input string stream
			istringstream iss(outputLine);
			try {
				iss >> convertedInt;
			}
			catch (...) {
				return failure_to_convert;
			}

			try {
				integers.push_back(convertedInt);
			}
			catch (...) {
				return failure_to_push_back;
			}
		}
		else {
			cout << outputLine << endl;
		}

	}

	//Iterate and print values of vectors containing integers converted from strings containing only digits
	for (size_t s = 0; s < integers.size(); s++) {
		cout << integers[s] << endl;
	}
	return success;
}

//takes a reference to a C++ style string (e.g., of type string) and modifies that string so that all of the alphabetic characters in it become lowercase
void lowercase(string &stringRef) {
	for (std::string::size_type i = 0; i < stringRef.size(); ++i) {
		if (stringRef[i] < 97) {
			stringRef[i] += 32;
		}
	}

	cout << stringRef << endl;

}


