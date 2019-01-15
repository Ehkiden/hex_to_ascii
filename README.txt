Project: 	Project 1
Class: 		CS 270 Section 001
Author: 	Jared Rigdon
Purpose: 	Read user input lines and convert decimal and hexadecimal to ascii format. Ctrl-D indicates the end of the input.
			If there are any invalid(malformed) characters and/or numbers, it will save it to a seperate array and display them
			at after the converstion is complete. The program will ignore and invalid input if between comment characters /* */.

Compile:	To compile the program, either type: make transform		
			or type: make
			This will compile an executable called transform.
			To execute the program, type: ./transform
			Then input the desired text and press enter and crtl+D to end the program.

Limitations:	We assume that there is a space surrounded by both /* */, and all hex and decimal numbers.
				We also assume there is no more than 1024 char input per line. 