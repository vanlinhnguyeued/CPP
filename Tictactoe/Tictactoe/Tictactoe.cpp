// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

string board[3][3] = { { "11","12","13" },{ "21","22","23" },{ "31","32","33" } };
int choice;
int row, column;
string turn = "X";
bool draw = false;
string namePlayer1, namePlayer2;


void getBoard() {
	cout << "\n\n\t   Tic Tac Toe\n\n";
	cout << "\t     |     |     " << endl;
	cout << "\t  " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2] << endl;

	cout << "\t     |     |     " << endl << endl;

}
void playerTurn(string namePlayer1, string namePlayer2) {
	if (turn == "X") {
		cout << "Your turn " << namePlayer1 << "- X: ";
	}
	else if (turn == "O") {
		cout << "Your turn " << namePlayer2 << "- O: ";
	}
	cin >> choice;
	if(choice)

	switch (choice) {
	case 11: row = 0; column = 0; break;
	case 12: row = 0; column = 1; break; 
	case 13: row = 0; column = 2; break; 
	case 21: row = 1; column = 0; break; 
	case 22: row = 1; column = 1; break; 
	case 23: row = 1; column = 2; break; 
	case 31: row = 2; column = 0; break; 
	case 32: row = 2; column = 1; break; 
	case 33: row = 2; column = 2; break;
	default:
		cout << "Invalid Move";
	}
	if (turn == "X" && board[row][column] != "X" && board[row][column] != "O") {
		board[row][column] = "X ";
		turn = "O";
	}
	else if (turn == "O" && board[row][column] != "X" && board[row][column] != "O") {
		board[row][column] = "O ";
		turn = "X";
	}
	else {
		cout << "Box already filled!\n Please choose another!!\n\n";
		playerTurn(namePlayer1, namePlayer2);
	}

}
bool checkGameOver() {
	for (int i = 0; i <3; i++) 
		if( board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;
	for (int i = 0; i<3; i++) 
		for (int j = 0; j<3; j++) 
			if (board[i][j] != "X" && board[i][j] != "O") 
				return true;

		draw = true;
		return false;

	
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

		while (checkGameOver()) {
			getBoard();
			playerTurn(namePlayer1, namePlayer2);
			checkGameOver();
		}
		if (turn == "X" && draw == false) {
			cout << "\n\n" << namePlayer2 << " winnnn!"<<endl;
		}
		else if (turn == "O" && draw == false) {
			cout << "\n\n" << namePlayer1 << " winnnn!"<<endl;
		}
		else cout << "\n\nDraw!!!"<<endl;
		
		system("pause");


		break;
	}
	default: 
		cout << "Exit game!";
		break;
	}
	return 0;
}
