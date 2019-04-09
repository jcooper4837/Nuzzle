// Program name : Nuzzle.cpp
// Author : Cooper Martin
// Date last updated : 4/8/2019
// Purpose : Nuzzle - Number Puzzle Game

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "Nuzzle.h"
using namespace std;
using namespace std::chrono;

int main()
{
	char playAgain = 'y';
	char move;
	int choice;
	bool isSolved;

	do
	{
		do
		{
			menu();
			cin >> choice;
		} while (choice < 1 || choice > 3);

		Nuzzle game(choice + 2);
		game.shuffleMatrix();
		game.outputMatrix();
		isSolved = false;
		seconds startTime = duration_cast<seconds>(system_clock::now().time_since_epoch());
		int count = 0;

		while (!isSolved)
		{
			cout << "\nEnter w for up, s for down, a for left, d for right: " << endl;
			cin >> move;
			count++;
			game.shiftMatrix(move);
			game.outputMatrix();
			isSolved = game.isValid();
		}

		seconds endTime = duration_cast<seconds>(system_clock::now().time_since_epoch());
		endTime -= startTime;
		cout << "\nCongratulations, you win!!" << endl;
		cout << "Time : " << endTime.count() << endl;
		cout << "Moves : " << count << endl;
		cout << "Play again? (y/n): ";
		cin >> playAgain;
	} while (playAgain == 'y');

	cin.get();
	cin.ignore();
	return 0;
}