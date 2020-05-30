#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int* convertToInt();
extern char * readInFile(char * filename, char grid[]);
extern void printGrid(char* grid);
extern int getNumberFromGrid(int row, int col, int * grid);

int main(int argc, char * argv[]){
	
	char grid[81];
	
	readInFile("puzzle.txt", grid);
	
	printGrid(grid);
	

	return 0;
}

int* convertToInt(){

	int * newGrid;
	
	return newGrid;

}

char * readInFile(char * filename, char grid[]){

	FILE * puzzle;
	puzzle = fopen("puzzle.txt", "r");
	char c;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			c = getc(puzzle);
			if(c == '\n')
				c = getc(puzzle);
			int index = ((i * 9) +j);
			grid[index] = c;
  		}
  	}
  	
  	return grid;

}

void printGrid(char* grid){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int index = ((i * 9) +j);
			printf("%c", grid[index]);
		}
		printf("\n");
	}
}

int getNumberFromGrid(int row, int col, int * grid){
	
	int ret;
	
	return ret;
	
}
