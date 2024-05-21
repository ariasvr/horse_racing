#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h>   
#include <windows.h>   
#include <MMsystem.h>
#include <math.h>
using namespace std;

void printHorizontal(int size){ //Print horizontal line
	for(int i=0; i<size; i++)
		cout<< " -------";
	cout<< "\n";
}

void printVertical(int size){ //Print vertical line
	cout<< "|";
	for(int i=0; i<size; i++)
		cout<< "       |";
	cout<< "\n";
}

//Zigzag map

void setBoardZigzag(int n, int pos[][7], int size, char board[][7], char name[][7], int numhorse){
	for (int i = 0; i < size*size; i++){
				if (i == 0) memcpy(board[i], " START", 7);
				else if (i == size*size - 1) memcpy(board[i], "FINISH!", 7);
				else memcpy(board[i], "     ", 7);
	}		
			
	for (int i = 0; i < numhorse; i++){
		for (int j = 0; j < n; j++){
			if (pos[i][j] != -1)
				memcpy(board[pos[i][j]], name[j], 7);
		}
	}
}

void printZigzag(char board[][7], int size){
	char left = 27, right = 26, down = 25;
	double len_name;
	double x;
	int y;
	for(int j = 0; j < size; j++){
		printHorizontal(size);
		printVertical(size);
		cout<< "|";
		if (j%2==0){
			for (int i=j*size; i<(j+1)*size; i++){
				len_name = strlen(board[i]);
				y = (7 - len_name)/2;
				if (y * 2 == (7 - len_name)) x = (7 - len_name)/2;
				else  x = (7 - len_name)/2 - 0.1;
				for (int r = 0; r < floor(x); r++ )
					cout<< " ";
				cout<< board[i];
				for (int r = 0; r < ceil(x); r++ )
					cout<< " ";
				cout<< "|";			
			}
		}
		else {
			for (int i=(j+1)*size-1; i>j*size-1; i--){
				len_name = strlen(board[i]);
				y = (7 - len_name)/2;
				if (y * 2 == (7 - len_name)) x = (7 - len_name)/2;
				else  x = (7 - len_name)/2 - 0.1;
				for (int r = 0; r < floor(x); r++ )
					cout<< " ";
				cout<< board[i];
				for (int r = 0; r < ceil(x); r++ )
					cout<< " ";
				cout<< "|";
			}
		}
		cout<< "\n";
		printVertical(size);
	}
	printHorizontal(size);
}

//Spiral map

void setBoardSpiral(int n, int pos[][7], int size, char board[][7], char name[][7], int numhorse){
	for (int i = 0; i < size*size; i++){
				if (i == 0) memcpy(board[i], "START", 7);
				else if (i == size*size - 1) memcpy(board[i], "FINISH", 7);
				else memcpy(board[i], "     ", 7);
	}		
			
	for (int i = 0; i < numhorse; i++){
		for (int j = 0; j < n; j++){
			if (pos[i][j] != -1)
				memcpy(board[pos[i][j]], name[j], 7);
		}
	}
}

void printSpiral3x3(char board[][7], int size, int map3[3][3]){
	double len_name;
	double x;
	int y;
	for(int i = 0; i < size; i++){
		printHorizontal(size);
		printVertical(size);
		cout<< "|";
		for (int j = 0; j < size; j++){
			len_name = strlen(board[map3[i][j]]);
			y = (7 - len_name)/2;
			if (y * 2 == (7 - len_name)) x = (7 - len_name)/2;
			else  x = (7 - len_name)/2 - 0.1;
			for (int r = 0; r < floor(x); r++ )
				cout<< " ";
			cout<< board[map3[i][j]];
			for (int r = 0; r < ceil(x); r++ )
				cout<< " ";
		cout<< "|";	
		}
		
		cout<< "\n";
		printVertical(size);
	}
	printHorizontal(size);
}

void printSpiral5x5(char board[][7], int size, int map5[5][5]){
	double len_name;
	double x;
	int y;
	for(int i = 0; i < size; i++){
		printHorizontal(size);
		printVertical(size);
		cout<< "|";
		for (int j = 0; j < size; j++){
			len_name = strlen(board[map5[i][j]]);
			y = (7 - len_name)/2;
			if (y * 2 == (7 - len_name)) x = (7 - len_name)/2;
			else  x = (7 - len_name)/2 - 0.1;
			for (int r = 0; r < floor(x); r++ )
				cout<< " ";
			cout<< board[map5[i][j]];
			for (int r = 0; r < ceil(x); r++ )
				cout<< " ";
			cout<< "|";
		}
		cout<< "\n";
		printVertical(size);
	}
	printHorizontal(size);
}

void printSpiral7x7(char board[][7], int size, int map7[7][7]){
	double len_name;
	double x;
	int y;
	for(int i = 0; i < size; i++){
		printHorizontal(size);
		printVertical(size);
		cout<< "|";
		for (int j = 0; j < size; j++){
			len_name = strlen(board[map7[i][j]]);
			y = (7 - len_name)/2;
			if (y * 2 == (7 - len_name)) x = (7 - len_name)/2;
			else  x = (7 - len_name)/2 - 0.1;
			for (int r = 0; r < floor(x); r++ )
				cout<< " ";
			cout<< board[map7[i][j]];
			for (int r = 0; r < ceil(x); r++ )
				cout<< " ";
			cout<< "|";
		}
		cout<< "\n";
		printVertical(size);
	}
	printHorizontal(size);
}
		
//Input players' name and set their information
void inputPlayer(int n, char name[][7], int size, int pos[][7], int numhorse){
	cout<< "Players' names setting. 6 characters are maximum.\n";
	for (int j = 0; j < n; j++){
			cout<< "Enter name of player " << j+1 << ": ";
			cin>> name[j];
        	for (int i = 0; i < numhorse; i++)
        		pos[i][j] = -1;
	}
}		

//Updating function
void player(int win_match[], char board[][7], char name[][7], int pos[][7], int size, int n, int numhorse, int choice, int map3[3][3], int map5[5][5], int map7[7][7]) {
	for (int j = 0; j < n; j++){
		for (int i = 0; i < numhorse; i++)
        		pos[i][j] = -1;}
	
	int winner[n];
	for (int i = 0; i < n; i++)
		winner[i] = -1;

	for (int mover = 0; winner[mover] <= 0; mover = (mover + 1) % n) {
		srand(time(NULL));
		int r;

		cout << name[mover] << " turn. Choose your horse number: ";
		cin >> r;
		while (r<0 || r > numhorse) {
			cout << "Invalid number. Enter again: ";
			cin >> r;
		}
		r--;

		int move = rand() % 6 + 1;
		cout << "Move: " << move << "\n";
		pos[r][mover] += move;
		if (pos[r][mover] > size * size - 1) {
			pos[r][mover] -= move;
			cout << name[mover] << " has an invalid step." << "\n";
		}
		else if (pos[r][mover] == size * size - 1) { //If the horse r of the player 'mover' reaches the finish line, winner of player 'mover' plus 1.
			cout << "Horse " << r + 1 << " of player " << name[mover] << " finished!\n";
			pos[r][mover] = size * size + 1; //Horse is removed from the board as soon as it reaches the finish line.
			winner[mover] += 1;
			if (winner[mover] == numhorse - 1) { //Because winner[] == -1 and r <= numhorse - 1, if all horses of a player reach finish line, winner[] == numhorse - 1
				win_match[mover]++;
				if (choice == 1) {
				setBoardZigzag(n, pos, size, board, name, numhorse);
				printZigzag(board, size);
				}
				if (choice == 2) {
				setBoardSpiral(n, pos, size, board, name, numhorse);
				if (size == 3) printSpiral3x3(board, size, map3);
				if (size == 5) printSpiral5x5(board, size, map5);
				if (size == 7) printSpiral7x7(board, size, map7);}
				cout << name[mover] << " win! \n";
				cout << "Number of winning matches: \n";
				for (int x = 0; x < n; x++)
					cout << name[x] << ": " << win_match[x] << endl;
				break;
			}
		}
		//If 2 or more horses belong to one player, they do not affect each other.
		else {
			for (int j = 0; j < n; j++) {
				for (int p = 0; p < numhorse; p++)
				{
					if (pos[r][mover] == pos[p][j] && mover != j)
					{
						pos[p][j] = -1;
						cout << name[j] << " is kicked by " << name[mover] << "\n";
					}
				}
			}
		}
		if (choice == 1) {
			setBoardZigzag(n, pos, size, board, name, numhorse);
			printZigzag(board, size);
		}
		if (choice == 2) {
			setBoardSpiral(n, pos, size, board, name, numhorse);
			if (size == 3) printSpiral3x3(board, size, map3);
			if (size == 5) printSpiral5x5(board, size, map5);
			if (size == 7) printSpiral7x7(board, size, map7);
		}
		cout << "\n";
		getch();
	}
	if (choice == 1) {
		setBoardZigzag(n, pos, size, board, name, numhorse);
		printZigzag(board, size);
	}
	if (choice == 2) {
		setBoardSpiral(n, pos, size, board, name, numhorse);
		if (size == 3) printSpiral3x3(board, size, map3);
		if (size == 5) printSpiral5x5(board, size, map5);
		if (size == 7) printSpiral7x7(board, size, map7);
	}
	cout << "\n";
	getch();
}

int main(){
	int size;
	int numhorse;
	int match = 0;
	char replay;
	char changecolor;
	int choice;
	char stop_music;
	
	//Play sound
	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	cout<< "Enter 'S' for turning off music ";
	cin>> stop_music;
		if (stop_music == 'S')
			PlaySound(NULL, 0, 0);
	//Source: https://www.youtube.com/watch?v=34d4iGHvm1g&ab_channel=Tajammal
	
	//Change color theme
	int k;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	for(k = 1; k < 255; k++)
  	{
    	SetConsoleTextAttribute(hConsole, k);
    	cout << k << " Choose me!" << endl;
  	}
  	SetConsoleTextAttribute(hConsole, 7);
  	cout<< "Do you want to change theme color of this game?\n";
	cout<< "Enter 'Y' for Yes and another character for 'No': ";
	cin>> changecolor;
	if (changecolor == 'Y'){
  		cout<< "Enter color number you want to apply: ";
  		cin>> k;
  		SetConsoleTextAttribute(hConsole, k);
	}
	//Source: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
	
	//Choose size of board
	cout<< "Enter the size of your board\n";
	cout<< "Enter 3 for 3x3 board\n";
	cout<< "Enter 5 for 5x5 board\n";
	cout<< "Enter 7 for 7x7 board\n";
	cin>> size;
	while (size != 3 && size != 5 && size != 7){
		cout<< "Invalid board size. Enter again!\n";
		cout<< "Enter the size of your board\n";
		cin>> size;
	}
	char board[size*size][7];
	
	//Choose number of players
	int n;
	cout<< "Choose number of players\n";
	cout<< "\t2 players\n";
	cout<< "\t3 players\n";
	cout<< "\t4 players\n";
	cout<< "Enter number of players: ";
	cin>> n;
	while (n < 2 || n > 4){
		cout<< "Invalid number of players. Enter again!\n";
		cout<< "Enter number of players: ";
		cin>> n;
	}
	
	//Create spiral map according to size
	int map3[3][3] = { {0, 1, 2},{7, 8, 3},{6, 5, 4} };

	int map5[5][5] = {{0, 1, 2, 3, 4},
			      	{15, 16, 17, 18, 5},
			  	  	{14, 23, 24, 19, 6},
			      	{13, 22, 21, 20, 7},
			  	  	{12, 11, 10, 9, 8} };

	int map7[7][7] = {{0, 1, 2, 3, 4, 5, 6},    
	 		      	{23, 24, 25, 26, 27, 28, 7},
			 	  	{22, 39, 40, 41, 42, 29, 8},
			  	  	{21, 38, 47, 48, 43, 30, 9},
			 	  	{20, 37, 46, 45, 44, 31, 10},
			 	 	{19, 36, 35, 34, 33, 32, 11},
			  	  	{18, 17, 16, 15, 14, 13, 12}};
			  	  	
	int win_match[n];
	for (int i = 0; i < n; i++)
		win_match[i] = 0;
	
	//CHoose number of horses
	cout<< "Choose number of horses\n";
	cout<< "\t2 horses\n";
	cout<< "\t3 horses \n";
	cout<< "\t4 horses\n";
	cout<< "Enter number of horses: ";
	cin>> numhorse;
	while (numhorse < 2 || numhorse > 4){
		cout<< "Invalid number of horses. Enter again!\n";
		cout<< "Enter number of horses: ";
		cin>> numhorse;
	}
	
	char name[n][7];
	int pos[numhorse][7];
	
	//Input player
	inputPlayer(n, name, size, pos, numhorse);
	
	cout<< "\tChoose a map\n";
	cout<< "1. Zigzag\n";
	cout<< "2. Spiral\n";
	cout<< "Enter your choice: ";
	cin>> choice;
	
	//Print board
	if (choice == 1){
		setBoardZigzag(n, pos, size, board, name, numhorse);
		printZigzag(board, size);}
	if (choice == 2){
		setBoardSpiral(n, pos, size, board, name, numhorse);
		if (size == 3) printSpiral3x3(board, size, map3);
		if (size == 5) printSpiral5x5(board, size, map5);
		if (size == 7) printSpiral7x7(board, size, map7);
	}

	
	//Replay?
	do{
		player(win_match, board, name, pos, size, n, numhorse, choice, map3, map5, map7);
		match++;
		cout<< "Replay? Enter 'Y' for Yes. Enter another character on keyboard for No: ";
		cin>> replay;
	}
	while (replay == 'Y');
	cout<< "Number of matches: " << match;
	return 0;
}
