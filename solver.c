#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void convertToInt();
extern void readInFile(char * filename, int grid[]);
extern void printGrid(int grid[]);
extern int getNumberFromGrid(int row, int col, int * grid);

int main(int argc, char * argv[]){
	
	char charGrid[81];
	int grid[81];
	
	readInFile("puzzle.txt", grid);	
	
	printGrid(grid);
	

	return 0;
}

void convertToInt(int grid[], char charGrid[]){
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int index = ((i * 9) +j);
			if(charGrid[index] == ' '){
				printf("-1\t");
				grid[index] = -1;
			}
			else{
				printf("%c\t", charGrid[index]);
				int temp = charGrid[index];
				printf("%d\t", temp);
				grid[index] = charGrid[index];
			}
  		}
  		printf("\n");
  	}

}

void readInFile(char * filename, int grid[]){

	FILE * puzzle;
	puzzle = fopen("puzzle.txt", "r");
	char c;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			c = getc(puzzle);
			if(c == '\n')
				c = getc(puzzle);
			int index = ((i * 9) +j);
			char str[2];
 			str[0] = c;
			str[1] = '\0';
 			grid[index] = (int) strtol(str, NULL, 10);
  		}
  	}
}

void printGrid(int grid[]){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int index = ((i * 9) +j);
			printf("%d", grid[index]);
		}
		printf("\n");
	}
}

int getNumberFromGrid(int row, int col, int grid[]){
	
	int ret;
	
	int index = ((row * 9) + col);
	
	return ret;
	
}
