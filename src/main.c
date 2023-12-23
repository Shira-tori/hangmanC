#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../headers/printHangman.h"

#define GAME_OVER 6

int getSizeOfString(char *string){
	int size = 0;
	for(int i = 0; string[i] != '\0'; i++){
		size++;
	}
	return size;
}

char* initGuess(int *num_of_char_in_word, char word[]){
	char prevchar;
	for(int i = 0; word[i] != '\0'; i++){
		if(word[i] != prevchar){
			*num_of_char_in_word = *num_of_char_in_word + 1;
			prevchar = word[i];
		}
	}
	char *guess = malloc(sizeof(char) * *num_of_char_in_word);

	return guess;
}

void getCharInput(char *input){
	*input = getchar();
	while(getchar() != '\n');
}

int checkIfCharInString(char string[], char *charc){
	for(int i = 0; string[i] != '\0'; i++){
		if(string[i] == *charc){
			return 1;
		}
	}
	return 0;
}

int initScreen(ulong *wrongs, char word[], char guess[], int *num_of_correct_guesses){
	int counter = 0;
	system("clear");
	printf("\t\tH A N G M A N\n");
	printf("\t   M A D E   B Y   S E A N\n");
	printHangman(wrongs);
	printf("\n\n\n\n");
	for(int i = 0; word[i] != '\0'; i++){
		if(checkIfCharInString(guess, &word[i])){
			printf(" %c  ", word[i]);
			counter++;
			continue;
		}
		printf("    ");
	}
	printf("\n");
	for(int i = 0; word[i] != '\0'; i++){
		printf("___ ");
	}
	printf("\n\n");
	return counter;
}



int main(){
	printf("Picking a random word...\n");
	char *word_to_guess = word();
	char input;
	int num_of_char_in_word;
	int num_of_correct_guesses = 0;
	ulong wrongs = 0;
	ulong size = getSizeOfString(word_to_guess);

	char *guess = initGuess(&num_of_char_in_word, word_to_guess);
	while(1){
		int num_of_letters = initScreen(&wrongs, word_to_guess, guess, &num_of_correct_guesses);
		if(num_of_letters == size){
			printf("You win!\n");
			break;
		}
		if(wrongs == GAME_OVER){
			char choice;
			printf("Game Over.\n");
			printf("Try Again? [Y/N]: ");
			getCharInput(&choice);
			switch(choice){
				case 'Y':
				case 'y':
					wrongs = 0;
					printf("Finding a new word...\n");
					word_to_guess = word();
					guess = initGuess(&num_of_char_in_word, word_to_guess);
					continue;
				case 'N':
				case 'n':
					break;
			}
			break;
		}

		printf("Guess a letter: ");
		getCharInput(&input);

		if(!checkIfCharInString(word_to_guess, &input)){
			wrongs++;
			continue;
		}

		if(!checkIfCharInString(guess, &input)){
			guess[num_of_correct_guesses] = input;
			num_of_correct_guesses++;
		}

	}
	free(guess);
	return 0;
}
