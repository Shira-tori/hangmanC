#include <stdio.h>
#include <stdlib.h>
#include "headers/printHangman.h"

void initScreen(int *wrongs, char word[], int *size, char guess[]){
	system("clear");
	printf("\t\tH A N G M A N\n");
	printf("\t   M A D E   B Y   S E A N\n");
	printHangman(wrongs);
	printf("\n\n");
	printf("\n");
	for(int i = 0; i < *size; i++){
		if(word[i] == guess[i]){
			printf("h%c  ", guess[i]);
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
	for(int i = 0; i < *size; i++){
		if(word[i] == *input){
			printf("Nice!\n");
			guess[i] == *input;
		}
		else{
			wrongs++;
		}
	}
}

void logic(int *wrongs, char word[], int *size, char guess[]){
	char input;
	while(1){
		printf("Guess a letter: ");
		getchar();
		scanf("%c", &input);	
		checkIfInputisInGuess(guess, word, &input, size, wrongs);
		initScreen(wrongs, word, size, guess);
	}
}


int main(){
	int wrongs = 0;
	char word[] = "TANGINA";
	int size = sizeof(word) / sizeof(char);
	char guess[size];
	for(int i = 0; i < size; i++){
		guess[i] = ' ';
	}
	initScreen(&wrongs, word, &size, guess);
	logic(&wrongs, word, &size, guess);
	return 0;
}
