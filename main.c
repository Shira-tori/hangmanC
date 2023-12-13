#include <stdio.h>
#include <stdlib.h>
#include "headers/printHangman.h"

int main();

void initScreen(int *wrongs, char word[], int *size, char guess[]){
	system("clear");
	printf("\t\tH A N G M A N\n");
	printf("\t   M A D E   B Y   S E A N\n");
	printHangman(wrongs);
	printf("\n\n");
	printf("\n");
	for(int i = 0; i < *size; i++){
		if(word[i] == guess[i]){
			printf(" %c  ", guess[i]);
		}
		else{
			printf("    ");
		}
	}
	printf("\n");
	for(int i = 0; i < *size-1; i++){
		printf("___ ");
	}
	printf("\n\n");
}

void checkIfInputisInGuess(char guess[], char word[], char *input, int *size, int *wrongs){
	// TODO: Find out how to check if input is right or wrong.
	for(int i = 0; word[i] != '\0'; i++){
		if(word[i] == input[0]){
			printf("Nice!\n");
			guess[i] = input[0];
		}
		else if(i == *size-2){
			*wrongs = *wrongs + 1;
		}
	}
}

void checkIfWinOrLose(char guess[], char word[], int *wrongs){
	if(*wrongs == 6){
		printf("\nGame Over.\n");
		while(1){
			printf("Try again?[Y/N]");
			switch(getchar()){
				case 'Y':
				case 'y':
					while(getchar() != '\n');
					main();
					break;
				case 'N':
				case 'n':
					exit(0);
			}
		}
	}
}

void logic(int *wrongs, char word[], int *size, char guess[]){
	char input;
	char buffer;
	while(1){
		printf("Guess a letter: ");
		input = getchar();
		while((getchar()) != '\n');
		checkIfInputisInGuess(guess, word, &input, size, wrongs);
		checkIfWinOrLose(guess, word, wrongs);
		initScreen(wrongs, word, size, guess);
	}
}

void initGuess(char guess[], int *size){
	for(int i = 0; i < *size; i++){
		guess[i] = ' ';
	}
}


int main(){
	int wrongs = 0;
	char word[] = "TANGINA";
	int size = sizeof(word) / sizeof(char);
	char guess[size];
	initGuess(guess, &size);
	initScreen(&wrongs, word, &size, guess);
	logic(&wrongs, word, &size, guess);
	return 0;
}
