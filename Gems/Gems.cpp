#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <cstdlib>

using namespace std;

const char X = 'X';
const char Y = 'Y';
const char O = 'O';

vector<char> FillTheBoard(vector<char>& board, const int BOARD_SIZE)
{
	int random_number;

	for (int i = 0; i < BOARD_SIZE; i++)
	{

		random_number = rand() % 3;

		switch (random_number)
		{
		case (0):
			board.push_back(X);
			break;
		case(1):
			board.push_back(Y);
			break;
		case(2):
			board.push_back(O);
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	}
	return board;
}
vector<char> FillTheCell(vector<char>& board, int number)
{
	int random_number = rand() % 3;
	switch (random_number)
	{
	case(0):
		board[number] = X;
		break;
	case(1):
		board[number] = Y;
		break;
	case(2):
		board[number] = O;
		break;
	default:
		break;
	}

	return board;
}
void GetBoard(vector<char>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		cout << board[i] << " ";
		if (i == 3 || i == 7 || i == 11 || i == 15)
		{
			cout << endl;
		}
	}
}
bool Check_Win(vector<char>& board)
{
	int Counter = 0;
	bool win = 0;
	for (int i = 0, k = 1; i < 15, k < 16; i++, k++)
	{
		if (board[i] == board[k])
		{
			Counter++;
			if (i == 3 || i == 7 || i == 11 || i == 15)
			{
				Counter = 0;
			}
		}
		else
		{
			Counter = 0;
		}

		if (Counter == 2 && k != 15)
		{
			if (board[i + 1] == board[k + 1])
			{
				Counter = 3;
				for (int j = 0; j <= Counter; j++)
				{
					FillTheCell(board, (k + 1) - j);
					win = 1;
				}
			}
			else
			{
				for (int j = 0; j <= Counter; j++)
				{
					FillTheCell(board, k - j);
					win = 1;
				}
			}
		}
		else if (Counter == 2)
		{
			for (int j = 0; j <= Counter; j++)
			{
				FillTheCell(board, k - j);
				win = 1;
			}
		}
	}
	return win;
}
bool Check_Win_Vert(vector<char>& board)
{
	int win = 0;
	int i = 0, k = 4, end = 12;

	for (int l = 0; l < 4; l++)
	{	
		int counter = 0;

		for ( i = l, k = i + 4; k <= end; i += 4, k += 4)
		{
			if (board[i] == board[k])
			{
				counter++;
			}
			else
			{
				counter = 0;
			}

			if (counter == 2 && (k != end))
			{
				if (board[i + 4] == board[k + 4])
				{
					counter = 3;

					for (int t = 0, u = 0; t <= counter; t++, u += 4)
					{
						FillTheCell(board, (k + 4) - u);
						win = 1;
					}
				}
				else
				{
					for (int t = 0, u = 0; t <= counter; t++, u += 4)
					{
						FillTheCell(board, k - u);
						win = 1;
					}
				}
			}
			else if (counter == 2)
			{
				for (int t = 0, u = 0; t <= counter; t++, u += 4)
				{
					FillTheCell(board, k - u);
					win = 1;
				}
			}
		}

		end++;
	}
	return win;
}
bool IsLegal(vector<char> board, int number_1, int number_2)
{
	char temp = board[number_1];
	
	if (number_1 - number_2 == 1 || number_2 - number_1 == 1 || number_1 - number_2 == 4 || number_2 - number_1 == 4)
	{
		board[number_1] = board[number_2];
		board[number_2] = temp;
	}

	if (Check_Win(board) == 1 || Check_Win_Vert(board) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector<char> Swap(vector<char>& board, int number_1, int number_2)
{
	int temp = board[number_1];

	if (IsLegal(board, number_1, number_2) == 1)
	{
		board[number_1] = board[number_2];
		board[number_2] = temp;
		return board;
	}
	else
	{
		return board;
	}
}



int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	
	vector<char> board;
	const int BOARD_SIZE = 16;
	FillTheBoard(board, BOARD_SIZE);
	GetBoard(board);
	cout << endl << endl << endl;

	while (Check_Win(board) || Check_Win_Vert(board))
	{
		Check_Win(board);
		Check_Win_Vert(board);
	}


	GetBoard (board);
	int number_1, number_2;
	cin >> number_1 >> number_2;
	while (number_1 != 100 && number_2 != 100)
	{
		Swap(board, number_1, number_2);
		while (Check_Win(board) || Check_Win_Vert(board))
		{
			Check_Win(board);
			Check_Win_Vert(board);

		}
		GetBoard(board);
		cin >> number_1 >> number_2;
	}
	
}

