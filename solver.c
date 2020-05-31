#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readInFile(char * filename, int grid[]);
void printGrid(int grid[]);
int getNumberFromGrid(int row, int col, int * grid);
bool legalNumber(int row, int col, int grid[], int num);
bool inRow(int row, int grid[], int num);
bool inCollum(int col, int grid[], int num);
bool inSquare(int row, int col, int grid[], int num);
bool isComplete(int grid[]);
bool solveSudoku(int grid[]);
bool notZero(int row, int col, int grid[]);
bool isPositionZero(int grid[], int * row, int * col);

int main(int argc, char * argv[]){
	
	char charGrid[81];
	int grid[81];
	
	readInFile("puzzle.txt", grid);	
	
	printGrid(grid);
	
	printf("\n");
	
	solveSudoku(grid);
	
	printGrid(grid);
	

	return 0;
}

void readInFile(char * filename, int grid[]){

	FILE * puzzle;
	puzzle = fopen(filename, "r");
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
	
	ret = grid[index];
	
	return ret;
	
}

bool legalNumber(int row, int col, int grid[], int num){
	
	if(!inRow(row, grid, num) && !inCollum(col, grid, num) && !inSquare(row, col, grid, num))
		return true;
	else
		return false;
	
}

bool inRow(int row, int grid[], int num){

	int startOfRow = row * 9;
	
	for(int i = 0; i < 9; i++){
		if(grid[startOfRow + i] == num)
			return true;
	}
	
	return false;

}

bool inCollum(int col, int grid[], int num){

	int tempCol = col;

	for(int i = 0; i < 9; i++){
		if(grid[tempCol] == num)
			return true;
		tempCol = tempCol + 9;
	
	}
	
	return false;
}

bool inSquare(int row, int col, int grid[], int num){
	
	int rowStart, colStart;
	
	if(row < 3)
		rowStart = 0;
	else if(row < 6)
		rowStart = 3;
	else
		rowStart = 6;
	if(col < 3)
		colStart = 0;
	else if(col < 6)
		colStart = 3;
	else
		colStart = 6;
	int index = ((rowStart * 9) + colStart);
		
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(grid[index] == num)
				return true;
			index++;
		}
		index = index + 6;
	}
	return false;
}

bool isComplete(int grid[]){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int index = ((i * 9) +j);
			if(grid[index] == 0)
				return false;
		}
	}
	
	return true;

}

bool solveSudoku(int grid[]){

	int row, col;
	
	if (!isPositionZero(grid, &row, &col)) 
        	return true; 
		
	for (int num = 1; num <= 9; num++) {
		if(legalNumber(row, col, grid, num)){
			int index = ((row * 9) + col);
			grid[index] = num;
				
			if(solveSudoku(grid))
				return true;
				
			grid[index] = 0;
		}
	}
	
	
	
	return false;

}

bool isPositionZero(int grid[], int * row, int * col){ 
    for ((*row) = 0; (*row) < 9; (*row)++){
        for ((*col) = 0; (*col) < 9; (*col)++){
        	int index = (((*row) * 9) + (*col));	
        	if (grid[index] == 0) 
               	return true; 
        }
    }
    return false; 
} 


















