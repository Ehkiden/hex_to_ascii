/*
Project: Project 1
Class: CS 270 Section 001
Author: Jared Rigdon
Purpose: Read user input lines and convert decimal and hexadecimal to ascii format. Ctrl-D indicates the end of the input.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	char uinput[1024];			//initial user input
	char* stringarray[1024];	//storing each line of user input
	char* invalid_tok[1024];	//array for invalid tokens
	int invalid_tok_cnt=0;		//amount of invalid tokens
	
	//read input until the eof(crtlD) is found and store in string array
	int len=0;	//actual length of the string array
	
	while(len<1024 && fgets(uinput, 1024+1, stdin)!=NULL){
 		stringarray[len]=strndup(uinput,1024); //assign to string	
 		len++;
 	}

 	printf("\n\n" );	//make it cleaner looking
	
	int is_comment=0; //check if there is an active comment section

 	//parse through each line and convert by each space
 	for(int j=0; j < len; j++){
 		char* buff;
 		buff=strtok(stringarray[j], " ");


 		//seperate by whitespace
 		while(buff != NULL){
	 		//check is str contains a newline char, if so, delete it 	 		
	 		int do_newline=0;
	 		char *newline=strchr(buff, '\n');
	 		if (newline){
	 			*newline=0;
	 			do_newline=1;
	 		}
 		
 			//check if a comment has began and/or ended
 			//assume comments are surrounded by whitespace
 			if (buff[0] == '/' && buff[1] == '*'){
 				is_comment=1;
 			}
 			if (buff[0] == '*' && buff[1] == '/'){
 				is_comment=0;
 			}

 			//if a comment character was detected, just print the following strings until end comment character
 			if (is_comment==1){
 				printf("%s ", buff);
 				//if there is a newline in between the comment char, make a newline
 				if (do_newline==1){
	 				printf("\n");
	 			}
 			}
 			else{
	 			//check if the buff is a hex and in 0xzz or 0Xzz format
	 			if(buff[0] == '0' && (buff[1] == 'x' || buff[1] == 'X') && strlen(buff) == 4){
	 				int con=0;
		 			con=strtol(buff,0,0);
		 			printf("%c", con);
	 			}
	 			//check if an int or string
	 			else{
	 				//loop through string and check if it is a number
	 				int count=0;
	 				int is_dig=0;	//assume it is a number at first
	 		
	 				while(count<strlen(buff) && is_dig !=1){
	 					if(!isdigit(buff[count])){
	 						is_dig=1;		
	 					}
	 					count++;
	 				}

	 				if(is_dig==0){
	 					//check if within ascii range
						int ascii_check=0;
						ascii_check=strtol(buff,NULL,10);
						if (ascii_check	< 256 && ascii_check >= 0){
							printf("%c", ascii_check);
						}
						else{
							//save to invalid token array
							invalid_tok[invalid_tok_cnt]=buff;
							invalid_tok_cnt++;
						}
	 				}
	 				//save to invalid token array
	 				else{
	 					if (buff[0] == '*' && buff[1] == '/'){
 							printf("%s", buff);
 						}
 						else{
 							invalid_tok[invalid_tok_cnt]=buff;
							invalid_tok_cnt++;
 						}
	 					
	 				}
	 			}
	 		}
	
	 		buff=strtok(NULL," ");
 		}	
 	}
 	if (invalid_tok_cnt>0){
 		//print out the invalid tokens
	 	printf("\nInvalid tokens:\n");
	 	for (int x=0;x<invalid_tok_cnt;x++){
	 		printf("%s ", invalid_tok[x]);
	 	}
 	}
 	
 	//to make it loook cleaner
 	printf("\n");
}
