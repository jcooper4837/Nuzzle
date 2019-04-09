// Program name : Nuzzle.h
// Author : Cooper Martin
// Date last updated : 4/8/2019
// Purpose : Nuzzle - Number Puzzle Game

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;


class Nuzzle
{
protected:

	int size;
	int *matrix;

public:

	Nuzzle(int s)
	{
		size = s;
		matrix = new int[size * size];
		int count = 1;

		for (int i = 0; i < (size * size) - 1; i++)
		{
			matrix[i] = count;
			count++;
		}

		matrix[(size * size) - 1] = 0;
	}

	void outputMatrix()
	{
		cout << "+-------+-------+-------+";

		if (size > 3)
		{
			cout << "-------+";
		}
		if (size > 4)
		{
			cout << "-------+";
		}
		cout << "\n";

		for (int i = 0; i < (size * size); i++)
		{
			if (i % size == 0)
			{
				cout << "|   ";
			}

			if (matrix[i] == 0)
			{
				cout <<  "    |   ";
			}
			else if (matrix[i] > 0 && matrix[i] < 10)
			{
				cout << matrix[i] << "   |   ";
			}
			else
			{
				cout << matrix[i] << "  |   ";
			}

			if ((i + 1) % size == 0)
			{
				cout << "\n+-------+-------+-------+";

				if (size > 3)
				{
					cout << "-------+";
				}
				if (size > 4)
				{
					cout << "-------+";
				}
				cout << "\n";
			}
		}
	}

	void shuffleMatrix()
	{
		do
		{
			matrix = new int[size * size];
			vector<int> list;
			int value;
			srand((unsigned)time(0));

			for (int i = 0; i < (size * size); i++)
			{
				do
				{
					value = rand() % ((size * size));
				} while (containsValue(list, value));

				matrix[i] = value;
				list.push_back(value);
			}
		} while (!isSolvable());
		cout << "\n";
	}

	bool containsValue(vector<int> list, int value)
	{
		int count = 0;

		if (list.size() != 0)
		{
			for (size_t i = 0; i < list.size(); i++)
			{
				if (list.at(i) == value)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool isSolvable()
	{
		int *list = new int[size * size];
		int count = 0;

		for (int i = 0; i < (size * size); i++)
		{
			list[count] = matrix[i];
			count++;
		}

		int parity = 0;
		int gridWidth = size;
		int row = 0;
		int blankRow = 0;

		for (int i = 0; i < (size * size); i++)
		{
			if (i % gridWidth == 0)
			{
				row++;
			}
			if (list[i] == 0)
			{
				blankRow = row;
				continue;
			}
			for (int j = i + 1; j < (size * size); j++)
			{
				if (list[i] > list[j] && list[j] != 0)
				{
					parity++;
				}
			}
		}

		if (gridWidth % 2 == 0)
		{
			if (blankRow % 2 == 0)
			{
				return parity % 2 == 0;
			}
			else
			{
				return parity % 2 != 0;
			}
		}
		else
		{
			return parity % 2 == 0;
		}
	}

	void shiftMatrix(char m)
	{
		int temp;

		if (m == 'w')
		{
			for (int i = 0; i < (size * size) - size; i++)
			{
				if (matrix[i] == 0)
				{
					temp = matrix[i + size];
					matrix[i + size] = matrix[i];
					matrix[i] = temp;
					return;
				}
			}
		}
		if (m == 's')
		{
			for (int i = size; i < (size * size); i++)
			{
				if (matrix[i] == 0)
				{
					temp = matrix[i - size];
					matrix[i - size] = matrix[i];
					matrix[i] = temp;
					return;
				}
			}
		}
		if (m == 'a')
		{
			for (int i = 0; i < (size * size); i++)
			{
				if (matrix[i] == 0 && (i + 1) % size != 0)
				{
					temp = matrix[i + 1];
					matrix[i + 1] = matrix[i];
					matrix[i] = temp;
					return;
				}
			}
		}
		if (m == 'd')
		{
			for (int i = 0; i < (size * size); i++)
			{
				if (matrix[i] == 0 && i % size != 0)
				{
					temp = matrix[i - 1];
					matrix[i - 1] = matrix[i];
					matrix[i] = temp;
					return;
				}
			}
		}
	}

	bool isValid()
	{
		int temp = 1;

		for (int i = 0; i < (size * size); i++)
		{
			if (i == (size * size - 1))
			{
				return true;
			}
			else if (temp != matrix[i])
			{
				return false;
			}

			temp++;
		}

		return true;
	}
};

static void menu()
{
	cout << "Select difficulty (1/2/3): " << endl;
	cout << "1: Easy (3x3)" << endl;
	cout << "2: Normal (4x4)" << endl;
	cout << "3: Hard (5x5)" << endl;
}