#pragma once
#include <vector>
#include <string>
using namespace std;


//Enumerations 
enum indices {
	programName = 0,
	inputFileName,
	numCmdLines = 2,
	numCmdLinesGomoku = 4
};

enum performance {
	success = 0,
	file_stream_not_open,
	failure_to_push_back,
	failure_to_convert,
	wrong_number_command_lines,
	could_not_extract,
	no_well_formatted_lines,
	vector_dimensions_mismatch,
	could_not_get_line,
	no_dimension_extracted,
	quit,
	no_more_turns,
	incorrectDimensions, 

};

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//Functions 
int usage(char * fileName, string message);
int parseFromFile(vector<string> & reference, char * fileName);
int iterateStringVector(vector<int> integers, vector<string> fileOutput);
void lowercase(string &stringRef);

#endif
