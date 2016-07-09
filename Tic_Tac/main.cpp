#include <iostream>
#include <windows.h>

#include "Table.h"
#include <conio.h>
using namespace std;

int ignore_few()
{
	int uIn = _getch();
	while (uIn == 224 || uIn == 0){
		uIn = _getch();
	}
	return uIn;	
};

int main()
{
	Table Board;

	int UserInput = 0;

	while (UserInput != 27)
	{
		Board.set_start_el(1,1);
		system("cls");	

		while (UserInput != 27 && Board.check_if_won() != 1 && Board.check_if_full() != 1)
		{
			Board.handle_user_input(UserInput);
			Board.use_in_main();
			UserInput = ignore_few();

			system("cls");		
		}
		
		system("cls");
		cout << "GAME OVER" << endl ;
		system("pause");
		system("cls");

		Board.restart_table();
	}
	
	return 0;
}