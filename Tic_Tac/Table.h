#ifndef Table_h
#define Table_h

#include <iostream>
#include <conio.h>
#include <windows.h>


#define TABLE_SIZE 3

using namespace std;

class Table
{

public:

	Table();
	~Table();

	void print_table();
	void restart_table();
	void set_start_el(int x, int y);
	void handle_user_input(int UserInput);
	void use_in_main();

	bool check_horizontal();
	bool check_vertical();
	bool check_diagonal_from_left();
	bool check_diagonal_from_right();

	bool check_if_won();
	bool check_if_full();

	char TableArr[TABLE_SIZE][TABLE_SIZE];
	int XPos, YPos;
	int summ;

private :

	const char DefaultSign;
	const char OSign, XSign; 

	int row, col;
	int x, y;	
	int XorO;


};

#endif