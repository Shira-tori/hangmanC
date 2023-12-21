#include <stdio.h>
#include <stdlib.h>
#include "../headers/printHangman.h"

#define GAME_OVER 6

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
	printf("\n\n");
	printf("\n");
	printf("\n");
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
	char word[] = "WATERFALL";
	char input;
	int num_of_char_in_word;
	int num_of_correct_guesses = 0;
	ulong wrongs = 0;
	ulong size = sizeof(word) / sizeof(char);

	char *guess = initGuess(&num_of_char_in_word, word);
	while(1){
		int num_of_letters = initScreen(&wrongs, word, guess, &num_of_correct_guesses);
		if(num_of_letters == size-1){
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
					continue;
				case 'N':
				case 'n':
					break;
			}
			break;
		}

		printf("Guess: ");
		getCharInput(&input);

		if(!checkIfCharInString(word, &input)){
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
