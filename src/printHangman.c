#include <stdio.h>
#include <stdlib.h>

void printHangman(ulong *wrongs){
	switch(*wrongs){
		case 0:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			break;
		case 1:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			break;
		case 2:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|         |\n");
			printf("\t|         |\n");
			printf("\t|         |\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			break;
		case 3:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|        /|\n");
			printf("\t|       / |\n");
			printf("\t|         |\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			break;
		case 4:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|        /|\\\n");
			printf("\t|       / | \\\n");
			printf("\t|         |\n");
			printf("\t|\n");
			printf("\t|\n");
			printf("\t|\n");
			break;
		case 5:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|        /|\\\n");
			printf("\t|       / | \\\n");
			printf("\t|         |\n");
			printf("\t|        / \n");
			printf("\t|       /   \n");
			printf("\t|\n");
			break;
		case 6:
			printf("\t___________\n");
			printf("\t|         |\n");
			printf("\t|         O\n");
			printf("\t|        /|\\\n");
			printf("\t|       / | \\\n");
			printf("\t|         |\n");
			printf("\t|        / \\\n");
			printf("\t|       /   \\\n");
			printf("\t|\n");
			break;
	}
}
