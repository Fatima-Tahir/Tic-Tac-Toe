#include<iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class TicTacToe
{
private:
	int size;
	char **board;

public:
	
	//Parameterized constructor
	TicTacToe(int size)
	{
		this->size=size;
		board = new char*[size];
		for(int i = 0; i < size; ++i)
		board[i] = new char[size];
		int x = 1;

		for(int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][j] = x ;
				x++;
			}
		}
	}

	//Check the cell is free or not
	bool isCellFree(int & row, int & col, int &location)
	{
		for(int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board [i][j] == location )
				{
					row = i;
					col = j;
				}
			}
		}

		if(board[row][col] != 'X' && board[row][col] != 'O' )
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	//Check the row is same or not
	bool isRow(int row)
	{
		int count1 = 0;
		int count2 = 0;
		for (int c = 0 ; c < size; c++)
		{
				if (board [row][c] == 'X')
					count1 ++;

				else if ( board [row][c] == 'O' )
					count2++;

				if (count1 == size || count2 == size)
				{
					return true;
				}
		}
		return false;
	}

	bool isRowSame()
	{
		for(int r = 0; r < size; r++)
		{
			if(isRow(r)) 
			{ 
				return true;
			}
		}
			return false;
	}

	//Check the column is same or not
	bool isCol(int col)
	{
		int count1 = 0;
		int count2 = 0;
		for (int r = 0 ; r < size; r++)
		{
				if (board [r][col] == 'X')
					count1 ++;

				else if ( board [r][col] == 'O' )
					count2++;

				if (count1 == size || count2 == size)
				{
					return true;
				}
		}
		return false;
	}

	bool isColSame()
	{
		for(int c = 0; c < size; c++)
		{
			if(isCol(c)) 
			{ 
				return true;	
			}
		}
			return false;
	}

	//Check the pre-diagnol is same or not
	bool IsPreDiagnolSame()
	 {
		int x = board [0][0];
		for(int i = 0; i < size; i++)
		{
			if(x != board [i][i] ) 
			{
				return false;
			}
		}
		return true;
	}

	//check the sec-diagnol is same or not
	bool IsSecDiagnolSame()
	{
		int x = board[0][size - 1];
		for(int i = 0; i < size; i++)
		{
			if(x != board [i][(size-1)-i] )
			{
				return false;
			}
		}
	return true;
	}

	//Check all the conditions of winning
	bool checkWin()
	{
		if(IsPreDiagnolSame()) 
		{
			return true;
		}
		else if(IsSecDiagnolSame()) 
		{
			return true;
		}
		else if(isRowSame())
		{
			return true;
		}
		else if(isColSame()) 
		{
			return true;
		}
		else
		{
			return false;
		}	
	}

	//Functions used to play game Human VS computer:
	//Check the row wise human win or not
	bool Row(int row)
	{
		int count = 0;
		static int location = 0;
		for (int c = 0 ; c < size; c++)
		{
				if (board [row][c] == 'O')
					count ++;

				if (count == size-1)
				{
					if(board[row][c] != 'O')
					{
						location = board[row][c];
						if(isCellFree(row,c,location))
						{
							board[row][c] = 'X';
							return true;
						}
					}
				}
		}
		return false;
	}

	bool CheckRow()
	{
		for(int r = 0; r < size; r++)
		{
			if(Row(r)) 
			{ 
				return true;
			}
		}
			return false;
	}

	//Check the column wise human win or not
	bool Col(int col)
	{
		static int location = 0;
		int count = 0;
		for (int r = 0 ; r < size; r++)
		{
				if (board [r][col] == 'O')
					count ++;

				if (count == size-1)
				{
					if(board[r][col] != 'O')
					{
						location = board[r][col];
						if(isCellFree(r,col,location))
						{
							board[r][col] = 'X';
							return true;
						}
					}
				}
		}
		return false;
	}

	bool CheckCol()
	{
		for(int c = 0; c < size; c++)
		{
			if(Col(c)) 
			{ 
				return true;	
			}
		}
			return false;
	}

	//Check the pre-diagnol wise human win or not
	bool CheckPreDiagnol()
	 {
		 static int location = 0;
		int count = 0;
		for(int i = 0; i < size; i++)
		{
			if( board [i][i] == 'O' ) 
				count ++;

			if(count == size-1)
			{
				if(board[i][i] != 'O')
				{
					location = board[i][i];
					if(isCellFree(i,i,location))
					{
						board[i][i] = 'X';
						return true;
					}
				}
			}
		}
		return false;
	}

	//check the sec-diagnol wise human win or not
	bool CheckSecDiagnol()
	{
		static int location = 0;
		int count = 0;
		int col = 0;
		for(int i = 0; i < size; i++)
		{
			if(board [i][(size-1)-i] == 'O' )
				count ++;

			if(board[i][(size-1)-i] != 'O')
			{
				location = board[i][(size-1)-i];
				col = ((size-1)-i);
				if(isCellFree(i,col,location))
				{
					board[i][(size-1)-i] = 'X';
					return true;
				}
			}
		}
		return false;
	}

	//Check all the conditions of winning
	bool checkHumanWin()
	{
		if(CheckPreDiagnol()) 
		{
			return true;
		}
		else if(CheckSecDiagnol()) 
		{
			return true;
		}
		else if(CheckRow())
		{
			return true;
		}
		else if(CheckCol()) 
		{
			return true;
		}
		else
		{
			return false;
		}	
	}


	//drawBoard function
	void drawBoard ()
	{
		for(int i = 0; i <size; i++)
		{
			for (int j = 0; j <size; j++)
			{
				if (board[i][j] != 'X' && board[i][j] != 'O')
				{
				
					cout <<setw(3) << static_cast<int>(board[i][j])<< " ";
				}
				else
					cout << setw(3) << board[i][j] << " ";
			}
			cout << endl;
		}	
	}

	//play game between two players
	void playPlayers (int &player)
	{
		bool flag = true;
		int location = 0;
		int row = 0;
		int col = 0;
		char character = 0;
		int count = 0;
		while(flag == true)
		{	
			cout << "Player " << player <<  " Select a location :  ";
			cin >> location;

			while(cin.fail() || location <= 0 || location > size*size)
			{
				cin.clear();
				cin.ignore();
				cout << "Player " << player << " Select a valid location again :  ";
				cin >> location;
			}

			if(player == 1) 
			{
				character = 'X';
			}
			else if(player == 2) 
			{
		 		character = 'O';
			} 

			if(isCellFree(row ,col, location ))
			{ 
				board[row][col] = character;
				player++; 
				flag = false;
			}

			else 
			{ 
				cout << " Invalid Move " << endl;	 
			}
		}
	}

	//Play game Human VS computer
	void playComputer (int &player)
	{
		bool flag = true;
		bool flag1 = true;
		int location1 = 0;
		int row = 0;
		int col = 0;
		char character = 0;
		static int count = 0;
		int location = 0;
		while(flag == true)
		{	
			if(player == 1) 
			{
				character = 'X';
			}
			else if(player == 2) 
			{
		 		character = 'O';
			} 

			if (player == 1)
			{

				cout << "Computer turns : " << endl;
				if(count >= 2)
				{ 
					if(checkHumanWin());
					player++; 
					flag = false;
				}

				 else
				 {
					srand (time (NULL) );
					location1 = (rand() % (size*size)) + 1;
					if(isCellFree(row ,col, location1 ))
					{ 
						board[row][col] = 'X';
						player++; 
						flag = false;	
					}
				 }
			}	

			else
			{
				cout << "Human : Select a location :  ";
				cin >> location;

				while(cin.fail() || location <= 0 || location > size*size)
				{
					cin.clear();
					cin.ignore();
					cout << "Human : Select a valid location again :  ";
					cin >> location;
				}
				if(isCellFree(row ,col, location ))
				{ 
					board[row][col] = character;
					player++; 
					flag = false;
					count++;
				}

				else 
				{ 
					cout << " Invalid Move " << endl;	 
				}
			}
		}
	}

	void ticTac(int &choice1)
	{
		int count = 0;
		int player = 1;
		bool flag = false;
	
		for(int i =0; i< size *size ; i++)
		{
			if (i % 2 == 0)
				player = 1;
			else
				player = 2;

			if (choice1 == 1)
			{
				playComputer (player);
				int check = checkWin();
				count ++;
				drawBoard();
				if(check) 
				{ 
					if (player-1 == 1)
					cout << "Computer wins ! " << endl;

					else
					cout << "Human wins !" << endl;

					flag = true;
					break;
				}
			}

			else
			{
				playPlayers(player);

				int check = checkWin();
				count ++;
				drawBoard();
				if(check) 
				{ 
					cout << "Congratulations player " << player - 1 << " won the game...!!" << endl;
					flag = true;
					break;
				}
			}
		}

		if (flag == false)
		{
			cout << "Game is draw." << endl ;
		}
	}

};


int main ()
{
	int choice1 = 0;
	int choice = 0;
	char ch;
	cout << "Welcome to Tic-Tac-Toe " << endl << endl;
	cout << "1. Single Player (Human vs Computer)" << endl << "2. Two Player (Human vs Human) " << endl;
	cout << "Enter your choice : " ;
	cin >> choice1 ;
	while (cin.fail() || choice1 <= 0 || choice1 > 2)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter a valid choice again : ";
		cin >> choice1;
	}

	cout << "Select playing grid " << endl;
	cout << "1. 3 * 3" << endl;
	cout << "2. 4 * 4" << endl;
	cout << "3. 5 * 5" << endl;
	cout << "Enter your choice : " ;
	cin >> choice ;

	while (cin.fail() || choice <= 0 || choice > 3)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter a valid choice again : ";
		cin >> choice;
	}

	if (choice == 1)
	{
		TicTacToe obj1(3);
		obj1.drawBoard();
		obj1.ticTac(choice1);
	}

	else if (choice == 2)
	{
		TicTacToe obj2(4);
		obj2.drawBoard();
		obj2.ticTac(choice1);
	}

	else if (choice == 3)
	{
		TicTacToe obj3(5);
		obj3.drawBoard();
		obj3.ticTac(choice1);
	}

	cout << endl;
	cout << "Do you want tp play again Y/N : ";
	cin >> ch;

	while(ch == 'Y' || ch == 'y')
	{
		cout << "Welcome to Tic-Tac-Toe " << endl << endl;
		cout << "1. Single Player (Human vs Computer)" << endl << "2. Two Player (Human vs Human) " << endl;
		cout << "Enter your choice : " ;
		cin >> choice1 ;
		while (cin.fail() || choice1 <= 0 || choice1 > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter a valid choice again : ";
			cin >> choice1;
		}

		cout << "Select playing grid " << endl;
		cout << "1. 3 * 3" << endl;
		cout << "2. 4 * 4" << endl;
		cout << "3. 5 * 5" << endl;
		cout << "Enter your choice : " ;
		cin >> choice ;

		while (cin.fail() || choice <= 0 || choice > 3)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter a valid choice again : ";
			cin >> choice;
		}

		if (choice == 1)
		{
			TicTacToe obj1(3);
			obj1.drawBoard();
			obj1.ticTac(choice1);
		}

		else if (choice == 2)
		{
			TicTacToe obj2(4);
			obj2.drawBoard();
			obj2.ticTac(choice1);
		}

		else if (choice == 3)
		{
			TicTacToe obj3(5);
			obj3.drawBoard();
			obj3.ticTac(choice1);
		}
		cout << endl;
		cout << "Do you want tp play again Y/N : ";
		cin >> ch;
	}

	if(ch != 'Y' || ch != 'y')
	{
		exit(0);

	}

	return 0;
}		