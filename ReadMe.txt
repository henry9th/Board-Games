Hyunrae Kim	Lab 3


Errors and Warnings: 

- I struggled a lot with formatting the board and using setw. Especially when working with the gomoku board, I would have difficulty preventing the spacing to leak into the next line.
- What was also difficult was refactoring previous code. Previously, I used a double array to hold values in the TicTacToe board, but having been required to dynamically set the dimensions, I instead used a double vector. 
- I also spent some time moving code into several different header and source files. 
- My original algorithm, shifting all the values and storing in a new double vector, for finding diagonals in a Gomoku board didn't account for much of the board.
- I had difficulty finding a bug that would abort the program. Turns out it was an issue in container indexing. 

Tests: 

- The same TicTacToe tests were ran. The game properly ends when a player wins and the when there are no remaining moves available. 

- I ran tests that called lab3.exe Gomoku and lab3.exe TicTacToe with the correct respective games being drawn. 

- With Gomoku, I tested wins vertically, horizontally, and diagonally in different corners of the board. I also made sure the 19,19 and other edge coordinates functioned properly and drawn properly. 

- The quit function works for both. 

Extra Credit: 

NOTE: The original assignment says that the return type for createGame should be a GameBase object, and in that way, I wasn't able to return any non-zero values that indicated an error, as the extra credit portion assignment said to do. Instead, I just print out the error message.

- Accomodating for both a three value input and a four value input, I tested both cases using different dimension values and consecutive number of pieces values. 

- All the different board dimensions were drawn properly

- When trying to enter values less than 1, the program will return the usage message. The same occurs when there are too many values inputted. 

lab3.exe Gomoku 5 2

5
4
3
2	W
1	W B
	1 2 3 4 5

Player W wins! 
