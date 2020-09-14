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


class Board
{
public:
	
	vector<char> FillTheBoard()
	{
		int random_number;
		
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			
			random_number = rand() % 3;

			switch (random_number)
			{
			case (0):
				m_board.push_back(X);
				break;
			case(1):
				m_board.push_back(Y);
				break;
			case(2):
				m_board.push_back(O);
				break;
			default:
				cout << "Error" << endl;
				break;
			}
		}
		return m_board;
	}

	vector<char> FillTheCell(int number)
	{
		int random_number = rand() % 3;
		switch (random_number)
		{
		case(0):
			m_board[number] = X;
			break;
		case(1):
			m_board[number] = Y;
			break;
		case(2):
			m_board[number] = O;
			break;
		default:
			break;
		}

		return m_board;
	}

	void GetBoard()
	{
		for (int i = 0; i < m_board.size(); i++)
		{
			cout << m_board[i] << " ";
			if (i == 3 || i == 7 || i == 11 || i == 15)
			{
				cout << endl;
			}
		}
	}
	protected:
	const int BOARD_SIZE = 16;
	vector<char> m_board;	
};

class Winner : public Board
{
public:
	void Check_Win()
	{
		for (int i = 0, k = 1; i < 15, k < 16; i++, k++)
		{
			if (m_board[i] == m_board[k])
			{
				m_Counter++;
				if (i == 3 || i == 7 || i == 1 || i == 15)
				{
					m_Counter = 0;
				}
			}
			else
			{
				m_Counter = 0;
			}

			if (m_Counter == 2 && k!= 15)
			{
				if (m_board[i+1] == m_board[k+1])
				{
					m_Counter = 3;
					for (int j = 0; j < m_Counter; j++)
					{
						FillTheCell((k+1)-j);
					}
				}
				else
				{
					for (int j = 0; j <= m_Counter; j++)
					{
						FillTheCell(k-j);
					}
				}
			}	
			else if (m_Counter == 2)
			{
				for (int j = 0; j < m_Counter; j++)
				{
					FillTheCell(k - j);
				}
			}
		}
	}
private:
	char m_Temp;
	int m_Counter = 0;

};

void bubble(int* a, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	
	Winner player1;
	player1.FillTheBoard();
	player1.GetBoard();
	cout << endl << endl << endl;
	player1.Check_Win();
	player1.GetBoard();
}

