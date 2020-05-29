#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int** convertToInt();
extern char** readInGrid(char * filename);
extern void printGrid(char** grid);

int main(int argc, char * argv[]){


	char ** grid = malloc(sizeof(char**));
	
	grid = readInGrid("puzzle.txt");
	
	//printGrid(grid);
	

	return 0;
}

int** convertToInt(){

	int ** newGrid;
	
	return newGrid;

}

char** readInGrid(char * filename){

	char ** grid = malloc(sizeof(char[9][9]));

	FILE * puzzle;
	puzzle = fopen("puzzle.txt", "r");
	char c;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			while ((c = getc(puzzle)) != EOF){
				printf("%c", c);
				//grid[i][j] = c;
  				//printf("%c",  grid[i][j]);
  			}
  		}
  	}
  	
  	return grid;

}

void printGrid(char** grid){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}
