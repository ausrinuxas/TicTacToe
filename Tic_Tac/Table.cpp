#include "Table.h"

Table::Table() : DefaultSign('.'), XSign('X'), OSign('O')
{
	restart_table();
};

Table::~Table(){};


void Table::print_table()
{
	for ( int y = 0; y < TABLE_SIZE; y++){
		cout << "         |";
		for ( int x = 0; x < TABLE_SIZE; x++){
			if (x==XPos && y==YPos && TableArr[y][x]==DefaultSign){
				if (XorO == 1) cout << " x";
				else cout << " o";
			}
			else
			cout << ' ' << TableArr[y][x];
			cout << " |";
		}
		cout << endl << "         _____________" << endl;
	}
};

void Table::restart_table()
{
	for ( int y = 0; y < TABLE_SIZE; y++){
		for ( int x = 0; x < TABLE_SIZE; x++){
			TableArr[y][x]=DefaultSign;
		}
	}

	XorO = 1;	//0 when O, 1 when X
};

void Table::set_start_el(int x, int y){
	XPos = x;
	YPos = y;
};


void Table::handle_user_input(int UserInput){
	if(UserInput == 224 || UserInput == 0) return;
	switch (UserInput){
		case 75:	//to the left
		{
			//cout << "_______________________________" << endl;
			if (XPos > 0)
				XPos--;
			break;
		}
		case 77:	//to the right
		{
			//cout << "_______________________________"  << endl;
			if (XPos < (TABLE_SIZE-1))
				XPos++;
			break;
		}
		case 72:	//to the top
		{
			//cout << "_______________________________" << endl;
			if (YPos > 0)
				YPos--;
			break;
		}
		case 80:	//to the bottom
		{
			//cout << "_______________________________" << endl;
			if (YPos < (TABLE_SIZE-1))
				YPos++;
			break;
		}
		case 13:	//pressed enter
		{
			if (TableArr[YPos][XPos] != DefaultSign)
				{
					cout << '\b' <<"Block is occupied, try another one." <<  endl;
					break;
				}
			else
			{
				//cout << endl;
				switch (XorO){
					case 0:		//O
					{
						TableArr[YPos][XPos] = OSign;
						++XorO;
						break;
					}
					case 1:		//X
					{
						TableArr[YPos][XPos] = XSign;
						--XorO;
						break;
					}
					default:
					{
						break;
					}
				}
				check_if_won();
				check_if_full();
			}
		}
		default:
		{
			break;
		}
	}
	
};

bool Table::check_horizontal()
{
	summ=0;
	for ( int y = 0; y < TABLE_SIZE; y++){
		summ = 0;
		for ( int x = 0; x < TABLE_SIZE; x++){
			if (TableArr[y][0] == TableArr[y][x] && TableArr[y][0] != DefaultSign){
				++summ;
			}
			else{
				break;
			}
		}
		if ( summ == TABLE_SIZE){
			cout << TableArr[y][0] << "  WON." << endl;
			return 1;
		}
	}
};

bool Table::check_vertical()
{
	summ=0;
	for ( int x = 0; x < TABLE_SIZE; x++){				//reversed 'for' version from check_horizontal()
		summ = 0;
		for ( int y = 0; y < TABLE_SIZE; y++){
			if (TableArr[0][x] == TableArr[y][x] && TableArr[0][x] != DefaultSign){
				++summ;
			}
			else{
				break;
			}
		}
		if ( summ == TABLE_SIZE){
			cout << TableArr[0][x] << "  WON." << endl;
			return 1;
		}
	}

};

bool Table::check_diagonal_from_left()
{
	summ=0;
	for ( int y = 0; y < TABLE_SIZE; y++){
		for ( int x = 0; x < TABLE_SIZE; x++){
			if (y == x && TableArr[0][0] == TableArr[y][x] && TableArr[0][0] != DefaultSign){
				++summ;
			}
		}
			if ( summ == TABLE_SIZE){
				cout << TableArr[0][0] << "  WON." << endl;
				return 1;
		}
	}
};

bool Table::check_diagonal_from_right()
{
	summ=0;
	int minn = TABLE_SIZE-1;
	for ( int y = 0; y < TABLE_SIZE; y++){
		for ( int x = 0; x < TABLE_SIZE; x++){
			if (y+x == minn && TableArr[0][minn] == TableArr[y][x] && TableArr[0][minn] != DefaultSign){
				++summ;
			}
		}
			if ( summ == TABLE_SIZE){
				cout << TableArr[0][minn] << "  WON." << endl;
				return 1;
		}
	}
};

bool Table::check_if_won()
{
	if (check_horizontal() == true)
		return 1;
	if (check_vertical() == true)
		return 1;
	if (check_diagonal_from_left() == true)
		return 1;
	if (check_diagonal_from_right() == true)
		return 1;
};

bool Table::check_if_full()
{
	for (int y = 0; y < TABLE_SIZE; y++){
		for (int x = 0; x < TABLE_SIZE; x++){
			if ( TableArr[y][x] == DefaultSign){
				return 0;
			}
		}
	}
	cout << "IT'S A TIE" << endl;
	return 1;
};

void Table::use_in_main()
{
		print_table();
		cout << endl;
		cout << "Sign already in this place:  " << TableArr[YPos][XPos];
		cout << endl;
};