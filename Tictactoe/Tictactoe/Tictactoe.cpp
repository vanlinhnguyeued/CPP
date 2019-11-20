// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

char s[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
int choice;
int row, column;
char turn = 'X';
bool draw = false;
string namePlayer1, namePlayer2;


void board() {
	cout << "\n\n\t   Tic Tac Toe\n\n";
	cout << "\t     |     |     " << endl;
	cout << "\t  " << s[0][0] << "  |  " << s[0][1] << "  |  " << s[0][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << s[1][0] << "  |  " << s[1][1] << "  |  " << s[1][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << s[2][0] << "  |  " << s[2][1] << "  |  " << s[2][2] << endl;

	cout << "\t     |     |     " << endl << endl;

}
void player_turn(string namePlayer1, string namePlayer2) {
	if (turn == 'X') {
		cout << "Your turn " << namePlayer1 << "- X: ";
	}
	else if (turn == 'O') {
		cout << "Your turn " << namePlayer2 << "- O: ";
	}
	cin >> choice;
	switch (choice) {
	case 11:
	{
		row = 0;
		column = 0;
		break;
	}
	case 12:
	{
		row = 0;
		column = 1;
		break;
	}
	case 13:
	{
		row = 0;
		column = 2;
		break;
	}
	case 21:
	{
		row = 1;
		column = 0;
		break;
	}
	case 22:
	{
		row = 1;
		column = 1;
		break;
	}
	case 23:
	{
		row = 1;
		column = 2;
		break;
	}
	case 31:
	{
		row = 2;
		column = 0;
		break;
	}
	case 32:
	{
		row = 2;
		column = 1;
		break;
	}
	case 33:
	{
		row = 2;
		column = 2;
		break;
	}
	default:
		cout << "Invalid Move";
	}
	if (turn == 'X' && s[row][column] != 'X' && s[row][column] != 'O') {
		s[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && s[row][column] != 'X' && s[row][column] != 'O') {
		s[row][column] = 'O';
		turn = 'X';
	}
	else {
		cout << "Box already filled!\n Please choose another!!\n\n";
		player_turn(namePlayer1, namePlayer2);
	}

}
bool checkWin() {
	for (int i = 0; i <3; i++) {
		if (s[i][0] == s[i][1] && s[i][0] == s[i][2] || s[0][i] == s[1][i] && s[0][i] == s[2][i])
			return true;
		if (s[0][0] == s[1][1] && s[0][0] == s[2][2] || s[0][2] == s[1][1] && s[0][2] == s[2][0])
			return true;
		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {
				if (s[i][j] != 'X' && s[i][j] != 'O') {
					return false;
				}
			}
		}
		draw = true;
		return true;

	}
}
int main() {
	cout << "Welcome To Tic-tac-toe game! Play with your way!\nIf you find any problem, please contact john.nguyen@gameloft.com" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):";

	char chooseMode;

	cin >> chooseMode;
	switch (chooseMode) {
	case '1': {
		cout << "Play game!" << endl;
		cout << "Enter Player 1 Name:";
		cin >> namePlayer1;
		cout << "Enter Player 2 Name:";
		cin >> namePlayer2;

		while (checkWin() == false) {
			board();
			player_turn(namePlayer1, namePlayer2);
			checkWin();
		}
		if (turn == 'X' && draw == false) {
			cout << "\n\n" << namePlayer1 << " winnnn!";
		}
		else if (turn == 'O' && draw == false) {
			cout << "\n\n" << namePlayer1 << " winnnn!";
		}
		else cout << "\n\nDraw!!!";



		break;
	}
	default: {
		cout << "Exit game!";
		break;
	}
	}
	return 0;
}