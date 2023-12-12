#include <stdio.h>
#include <stdlib.h>
#include "headers/printHangman.h"

void logic(int *wrongs, char word[], int size){
	printf("\n\t");
	for(int i = 0; i < size; i++){
		printf("___ ");
	}
	printf("\n");
	
}

void initScreen(){
	system("clear");
	printf("\t\tH A N G M A N\n");
	printf("\t   M A D E   B Y   S E A N\n");
}

int main(){
	char word[] = "FABULOUS";
	int wrongs = 0;
	initScreen();
	printHangman(&wrongs);
	logic(&wrongs, word, sizeof(word) / sizeof(char));
	return 0;
}
