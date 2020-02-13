#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h> 
#include"time.h"
#include<MMSystem.h>
using namespace std;

#define cls system("cls");
#define stop system("pause");

struct map_args
{
	const int map_size = 10;
	int ship_size = 0;
	int map[10][10]{};
	int numb = 0;
	char letter = 'A';
	int ship_s1 = 0,
		ship_s2 = 0,
		ship_s3 = 0,
		ship_s4 = 0;
	int ship_state = 1;

};
void res_map(int map[][10])//resetting map 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = 0;
		}
	}


}
void show_map(int map[][10], int c_map[][10], int size, int m_ship_s1, int m_ship_s2, int m_ship_s3, int m_ship_s4, char letter, int numb, bool  show)//m_-main_ship
{

	char ship_s4[4] = { 219,219,219,219 };
	char ship_s3[3] = { 219,219,219 };
	char ship_s2[2] = { 219,219 };
	char ship_s1[1] = { 219 };
	int ship_color = 0;
	size = 10;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	cls
		if (!show)
		{
			cout << " ***PLACE YOUR SHIPS*** \n\n";
		}
	cout << " ";
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(h, 15);
		cout << i << " ";


	}
	if (show)
	{
		cout << "\t\t\t ";
		for (int i = 0; i < 10; i++)
		{
			cout << i << " ";

		}
	}
	if (!show)
	{
		cout << "\t\t\tAll ships";
	}
	cout << " ";


	//**********SHOW THE PLAYER's MAP(start)

	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		SetConsoleTextAttribute(h, 15);

		cout << char(65 + i);
		SetConsoleTextAttribute(h, 9);

		for (int j = 0; j < 10; j++)
		{


			if (map[i][j] == 5)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "XX"; //around of destroyed ship
				SetConsoleTextAttribute(h, FOREGROUND_RED);
			}
			if (map[i][j] == 4)
			{
				SetConsoleTextAttribute(h, 6);
				cout << char(219) << char(219); //destroyed ship
				SetConsoleTextAttribute(h, 6);
			}
			if (map[i][j] == 3)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "XX"; //detected ship
				SetConsoleTextAttribute(h, FOREGROUND_RED);
			}
			if (map[i][j] == 2)
			{
				SetConsoleTextAttribute(h, 1);
				cout << char(176) << char(176);//empty field
				SetConsoleTextAttribute(h, 1);
			}


			if (map[i][j] == 1)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				cout << char(219) << char(219);//ship
			}
			else if (map[i][j] == 0 || map[i][j] == 6) 
			{
				SetConsoleTextAttribute(h, 9);
				cout << char(177) << char(177);//field
			}




		}
		//				**********SHOW THE PLAYER's MAP(end)

		//				**********SHOW THE COMPUTER's MAP(start)

		if (show)
		{
			cout << "\t\t\t";
			SetConsoleTextAttribute(h, 15);

			cout << char(65 + i);
			SetConsoleTextAttribute(h, 9);
			for (int j = 0; j < 10; j++)
			{
				if (c_map[i][j] == 5)
				{
					SetConsoleTextAttribute(h, FOREGROUND_RED);
					cout << "XX"; //around of destroyed ship
					SetConsoleTextAttribute(h, FOREGROUND_RED);
				}
				if (c_map[i][j] == 4)
				{
					SetConsoleTextAttribute(h, 6);
					cout << char(219) << char(219); //destroyed ship
					SetConsoleTextAttribute(h, 6);
				}
				if (c_map[i][j] == 3)
				{
					SetConsoleTextAttribute(h, FOREGROUND_RED);
					cout << "XX"; //detected ship
					SetConsoleTextAttribute(h, FOREGROUND_RED);
				}
				if (c_map[i][j] == 2)
				{
					SetConsoleTextAttribute(h, 1);
					cout << char(176) << char(176);//empty field
					SetConsoleTextAttribute(h, 1);
				}


				/*if (c_map[i][j] == 1)
				{
					SetConsoleTextAttribute(h, FOREGROUND_GREEN);
					cout << char(219) << char(219);//ship
				}*/

				else if (c_map[i][j] == 0 || c_map[i][j] == 6|| c_map[i][j] == 1)
				{
					SetConsoleTextAttribute(h, 9);
					cout << char(177) << char(177);//field
				}


			}

		}

		//**********SHOW THE COMPUTER's MAP(end)



		cout << "\t\t\t";
		//all ships

		if (!show)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);

			if (i == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					if (m_ship_s4 != 1)
					{

						cout << ship_s4[i];
					}
					else
					{
						break;
					}
				}
			}
			else if (i == 2)
			{
				for (int i = 0; i < 3; i++)
				{
					if (m_ship_s3 != 2)
					{

						cout << ship_s3[i];
					}
					else
					{
						break;
					}
				}
				cout << " ";
				for (int i = 0; i < 3; i++)
				{
					if (m_ship_s3 != 1 && m_ship_s3 != 2)
					{

						cout << ship_s3[i];
					}
					else
					{
						break;
					}

				}
			}
			else if (i == 4)
			{
				for (int i = 0; i < 2; i++)
				{
					if (m_ship_s2 != 3)
					{

						cout << ship_s2[i];
					}
					else break;
				}
				cout << " ";
				for (int i = 0; i < 2; i++)
				{
					if (m_ship_s2 != 2 && m_ship_s2 != 3)
					{

						cout << ship_s2[i];
					}
					else break;
				}
				cout << " ";
				for (int i = 0; i < 2; i++)
				{
					if (m_ship_s2 != 1 && m_ship_s2 != 2 && m_ship_s2 != 3)
					{

						cout << ship_s2[i];
					}
					else break;
				}
			}
			else if (i == 6)
			{
				for (int i = 0; i < 1; i++)
				{
					if (m_ship_s1 != 4)
					{

						cout << ship_s1[i];
					}
					else
						break;
				}
				cout << " ";
				for (int i = 0; i < 1; i++)
				{
					if (m_ship_s1 != 3 && m_ship_s1 != 4)
					{
						cout << ship_s1[i];
					}
					else break;
				}
				cout << " ";
				for (int i = 0; i < 1; i++)
				{
					if (m_ship_s1 != 2 && m_ship_s1 != 3 && m_ship_s1 != 4)
					{
						cout << ship_s1[i];

					}
					else break;
				}
				cout << " ";
				for (int i = 0; i < 1; i++)
				{
					if (m_ship_s1 != 1 && m_ship_s1 != 2 && m_ship_s1 != 3 && m_ship_s1 != 4)
					{
						cout << ship_s1[i];

					}
					else break;
				}
			}
		}
		//all ships

		cout << endl;

	}


}

void player_turn(int map[][10], int x, int y, int* snd_numb)
{

	bool check = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	
	int count = 0;
	int size = 4;

	if (map[x][y] == 1)
	{
		map[x][y] = 3;
		check = 1;
	}

	if (check)
	{

		for (int i = 0; i < size; i++)
		{
			if (map[x][y + i] == 3)
			{
				check = 1;
			}
			else
			{
				for (int j = 1; j <= size - i; j++)
				{
					if (map[x][y -  j] == 3)
					{
						check = 1;
					}
					else
					{
						check = 0;
						break;
					}
				}

			 
			}
			if (!check)
			{
				check = 0;
				break;
			}
			//bu kod hissəsi işləmir (məntiqi səhv var)
		/*	if (!check)
			{

				size -= 1;
				i = 0;
			}
			if (size==0)
			{

				break;
			}*/
		}

	}

	if (check)
	{
		if (y + size <= 9)
		{
			a= map[x][y + size];
			map[x][y + size] = 5;
		}
		
		if (y + size <= 9&&x!=9)
		{
			b = map[x + 1][y + size];
			map[x+1][y + size] = 5;
		}
		
		if (y + size <= 9 && x != 0)
		{
			c = map[x - 1][y + size];
			map[x - 1][y + size] = 5;
		}
		if (y - 1 >= 0)
		{
			d = map[x][y-1];
			map[x][y-1] = 5;
		}
		for (int i = 0; i < size; i++)
		{
			if (map[x][y + i] == 3)
			{
				map[x][y + i] = 4;
				if (x!=0)
				{
					map[x-1][y + i] = 5;
				}
				if (x != 9)
				{
					map[x + 1][y + i] = 5;
				}
				
			}
			else
			{
				
				map[x][y + size] = a;
				map[x + 1][y + size]=b;
				map[x - 1][y + size]=c;
				map[x][y - 1]=d;
				if (y + i <= 9)
				{
					map[x][y + i] = 5;
				}
				if (y + i <= 9&&x!=9)
				{
					map[x+1][y + i] = 5;
				}
				if (y + i <= 9 && x != 0)
				{
					map[x - 1][y + i] = 5;
				}
				 
				for (int j = 1; j <= size - i; j++)
				{
					if (map[x][y - j] == 3)
					{
						map[x][y - j] = 4;
						if (x != 0)
						{
							map[x-1][y - j] = 5;
						}
						if (x != 9)
						{
							map[x + 1][y - j] = 5;
						}
						
					}	
					if (j == size-i)
					{
						check = 0;
						break;
					}
				}
				
			}
			if (!check)
			{
				break;
			}
		}
	}
	 
	 

//checking for empty field(start)

if (map[x][y] == 0 || map[x][y] == 6)
{
	map[x][y] = 2;//empty field
	*snd_numb = 0;//WaterSplash sound
}
else
{

	*snd_numb = 1;//explosion sound
}
//checking for empty field(end)

}

bool check_ships_around(int map[][10], int x, int y, bool select, int ship_size)
{

	if (!select)
	{
		if (y == 9 && ship_size > 1)
		{
			y -= ship_size - 1;

		}
		if (y == 8 && ship_size > 2)
		{
			y -= ship_size - 2;

		}
		if (y == 7 && ship_size > 3)
		{
			y -= ship_size - 3;


		}
		for (int i = 0; i < ship_size; i++)
		{
			if (map[x][y + i] == 6 || map[x][y + i] == 1)
			{
				return 0;
			}
		}
	}
	else
	{
		if (x == 9 && ship_size > 1)
		{
			x -= ship_size - 1;

		}
		if (x == 8 && ship_size > 2)
		{
			y -= ship_size - 2;

		}
		if (x == 7 && ship_size > 3)
		{
			x -= ship_size - 3;


		}
		for (int i = 0; i < ship_size; i++)
		{
			if (map[x + i][y] == 6 || map[x + i][y] == 1)
			{
				return 0;
			}
		}
	}
	return 1;
}
void auto_place(int map[][10], int* ship_s1, int* ship_s2, int* ship_s3, int* ship_s4)

{

	int x = 0;
	int y = 0;
	bool select = 0;
	bool chk = 1;
	int ship_size = 0;
	//assigning 4 sized ship (start)
	select = rand() % 2;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 7;
		for (int i = 0; i < 4; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 6)
		{
			map[x][y + 4] = 6;
			map[x - 1][y + 4] = 6;
			map[x + 1][y + 4] = 6;

		}
	}
	else
	{
		x = rand() % 7;
		y = rand() % 10;
		for (int i = 0; i < 4; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 6)
		{
			map[x + 4][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 4][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 4][y - 1] = 6;
		}
	}
	//assigning 4 sized ship (end)

	//assigning 3 sized ship (start)
	select = rand() % 2;
	ship_size = 3;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 8;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 10;
			y = rand() % 8;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 3; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 7)
		{
			map[x][y + 3] = 6;
			map[x - 1][y + 3] = 6;
			map[x + 1][y + 3] = 6;

		}
	}
	else
	{
		x = rand() % 8;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 7;
			y = rand() % 10;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 3; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 7)
		{
			map[x + 3][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 3][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 3][y - 1] = 6;
		}
	}

	//assigning 3 sized ship (end)

	//assigning 3 sized ship_2 (start)
	select = rand() % 2;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 8;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 10;
			y = rand() % 8;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 3; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 7)
		{
			map[x][y + 3] = 6;
			map[x - 1][y + 3] = 6;
			map[x + 1][y + 3] = 6;

		}
	}
	else
	{
		x = rand() % 8;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 7;
			y = rand() % 10;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 3; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 7)
		{
			map[x + 3][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 3][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 3][y - 1] = 6;
		}
	}
	//assigning 3 sized ship_2 (end)

	//assigning 2 sized ship (start)
	select = rand() % 2;
	ship_size = 2;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 9;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 10;
			y = rand() % 9;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 8)
		{
			map[x][y + 2] = 6;
			map[x - 1][y + 2] = 6;
			map[x + 1][y + 2] = 6;

		}
	}
	else
	{
		x = rand() % 9;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 9;
			y = rand() % 10;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 8)
		{
			map[x + 2][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 2][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 2][y - 1] = 6;
		}
	}
	//assigning 2 sized ship (end)
	//assigning 2 sized ship_2 (start)
	select = rand() % 2;
	ship_size = 2;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 9;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 10;
			y = rand() % 9;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 8)
		{
			map[x][y + 2] = 6;
			map[x - 1][y + 2] = 6;
			map[x + 1][y + 2] = 6;

		}
	}
	else
	{
		x = rand() % 9;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 9;
			y = rand() % 10;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 8)
		{
			map[x + 2][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 2][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 2][y - 1] = 6;
		}
	}
	//assigning 2 sized ship_2 (end)
	//assigning 2 sized ship_3 (start)
	select = rand() % 2;
	ship_size = 2;
	if (!select)
	{
		x = rand() % 10;
		y = rand() % 9;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 10;
			y = rand() % 9;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x][y + i] = 1;
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
		}
		if (y != 0)
		{
			map[x][y - 1] = 6;
			map[x - 1][y - 1] = 6;
			map[x + 1][y - 1] = 6;

		}
		if (y != 8)
		{
			map[x][y + 2] = 6;
			map[x - 1][y + 2] = 6;
			map[x + 1][y + 2] = 6;

		}
	}
	else
	{
		x = rand() % 9;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
		while (!chk)
		{
			x = rand() % 9;
			y = rand() % 10;
			chk = check_ships_around(map, x, y, select, ship_size);
		}
		for (int i = 0; i < 2; i++)
		{
			map[x + i][y] = 1;
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 8)
		{
			map[x + 2][y] = 6;
		}
		if (y != 9)
		{
			map[x - 1][y + 1] = 6;
			map[x + 2][y + 1] = 6;
		}
		if (y != 0)
		{
			map[x - 1][y - 1] = 6;
			map[x + 2][y - 1] = 6;
		}
	}
	//assigning 2 sized ship_3 (end)

	//assigning 1 sized ship (start)	
	ship_size = 1;

	x = rand() % 10;
	y = rand() % 10;
	chk = check_ships_around(map, x, y, select, ship_size);
	while (!chk)
	{
		x = rand() % 10;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
	}
	for (int i = 0; i < 1; i++)
	{
		map[x][y + i] = 1;
		if (x != 0)
		{
			map[x - 1][y + i] = 6;
		}
		if (x != 9)
		{
			map[x + 1][y + i] = 6;
		}
	}
	if (y != 0)
	{
		map[x][y - 1] = 6;
		map[x - 1][y - 1] = 6;
		map[x + 1][y - 1] = 6;

	}
	if (y != 9)
	{
		map[x][y + 1] = 6;
		map[x - 1][y + 1] = 6;
		map[x + 1][y + 1] = 6;

	}


	//assigning 1 sized ship (end)

	//assigning 1 sized ship_2 (start)	
	ship_size = 1;

	x = rand() % 10;
	y = rand() % 10;
	chk = check_ships_around(map, x, y, select, ship_size);
	while (!chk)
	{
		x = rand() % 10;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
	}
	for (int i = 0; i < 1; i++)
	{
		map[x][y + i] = 1;
		if (x != 0)
		{
			map[x - 1][y + i] = 6;
		}
		if (x != 9)
		{
			map[x + 1][y + i] = 6;
		}
	}
	if (y != 0)
	{
		map[x][y - 1] = 6;
		map[x - 1][y - 1] = 6;
		map[x + 1][y - 1] = 6;

	}
	if (y != 9)
	{
		map[x][y + 1] = 6;
		map[x - 1][y + 1] = 6;
		map[x + 1][y + 1] = 6;

	}


	//assigning 1 sized ship_2 (end)
	//assigning 1 sized ship_3 (start)	
	ship_size = 1;

	x = rand() % 10;
	y = rand() % 10;
	chk = check_ships_around(map, x, y, select, ship_size);
	while (!chk)
	{
		x = rand() % 10;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
	}
	for (int i = 0; i < 1; i++)
	{
		map[x][y + i] = 1;
		if (x != 0)
		{
			map[x - 1][y + i] = 6;
		}
		if (x != 9)
		{
			map[x + 1][y + i] = 6;
		}
	}
	if (y != 0)
	{
		map[x][y - 1] = 6;
		map[x - 1][y - 1] = 6;
		map[x + 1][y - 1] = 6;

	}
	if (y != 9)
	{
		map[x][y + 1] = 6;
		map[x - 1][y + 1] = 6;
		map[x + 1][y + 1] = 6;

	}


	//assigning 1 sized ship_3 (end)
	//assigning 1 sized ship_4 (start)	
	ship_size = 1;

	x = rand() % 10;
	y = rand() % 10;
	chk = check_ships_around(map, x, y, select, ship_size);
	while (!chk)
	{
		x = rand() % 10;
		y = rand() % 10;
		chk = check_ships_around(map, x, y, select, ship_size);
	}
	for (int i = 0; i < 1; i++)
	{
		map[x][y + i] = 1;
		if (x != 0)
		{
			map[x - 1][y + i] = 6;
		}
		if (x != 9)
		{
			map[x + 1][y + i] = 6;
		}
	}
	if (y != 0)
	{
		map[x][y - 1] = 6;
		map[x - 1][y - 1] = 6;
		map[x + 1][y - 1] = 6;

	}
	if (y != 9)
	{
		map[x][y + 1] = 6;
		map[x - 1][y + 1] = 6;
		map[x + 1][y + 1] = 6;

	}


	//assigning 1 sized ship_4 (end)
	*ship_s1 = 4;
	*ship_s2 = 3;
	*ship_s3 = 2;
	*ship_s4 = 1;
}
void manual_place(int map[][10], int ship_size, int x, int y, int* ship_s1, int* ship_s2, int* ship_s3, int* ship_s4, char choice, bool* select)
{

	if (choice == '1')
	{
		*select = 0;
	}
	else if (choice == '2')
	{
		*select = 1;
	}
	if (ship_size == 1)
	{
		*ship_s1 += 1;
	}
	else if (ship_size == 2)
	{
		*ship_s2 += 1;
	}
	else if (ship_size == 3)
	{
		*ship_s3 += 1;
	}
	else if (ship_size == 4)
	{
		*ship_s4 += 1;
	}


	//				*** ASSIGNING SHIPS HORIZONTALLY *** (start)

	if (choice == '1')
	{
		if (y == 9 && ship_size > 1)
		{
			y -= ship_size - 1;

		}
		if (y == 8 && ship_size > 2)
		{
			y -= ship_size - 2;

		}
		if (y == 7 && ship_size > 3)
		{
			y -= ship_size - 3;


		}


		for (int i = 0; i < ship_size; i++)
		{

			map[x][y + i] = 1;
			if (y + ship_size <= 9)
			{
				map[x][y + ship_size] = 6;
			}
			if (y + ship_size <= 9 && x != 0)
			{
				map[x - 1][y + ship_size] = 6;
			}
			if (y + ship_size <= 9 && x != 9)
			{
				map[x + 1][y + ship_size] = 6;
			}
			if (y != 0)
			{
				map[x][y - 1] = 6;
			}
			if (y != 0 && x != 0)
			{
				map[x - 1][y - 1] = 6;
			}
			if (y != 0 && x != 9)
			{
				map[x + 1][y - 1] = 6;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 6;
			}
			if (x != 0)
			{
				map[x - 1][y + i] = 6;
			}
		}
	}

	//						*** ASSIGNING SHIPS HORIZONTALLY *** (end)

	//				*** ASSIGNING SHIPS VERTICALLY *** (start)
	else if (choice == '2')
	{

		if (x == 9 && ship_size > 1)
		{
			x -= ship_size - 1;

		}
		if (x == 8 && ship_size > 2)
		{
			y -= ship_size - 2;

		}
		if (x == 7 && ship_size > 3)
		{
			x -= ship_size - 3;

		}
		if (x + ship_size <= 9)
		{
			map[x + ship_size][y] = 6;
		}
		if (x + ship_size <= 9 && y != 9)
		{
			map[x + ship_size][y + 1] = 6;
		}
		if (x + ship_size <= 9 && y != 0)
		{
			map[x + ship_size][y - 1] = 6;
		}
		if (x != 0)
		{
			map[x - 1][y] = 6;
		}
		if (x != 0 && y != 9)
		{
			map[x - 1][y + 1] = 6;
		}
		if (x != 0 && y != 0)
		{
			map[x - 1][y - 1] = 6;
		}
		for (int i = 0; i < ship_size; i++)
		{

			map[x + i][y] = 1;
			if (y != 9)
			{
				map[x + i][y + 1] = 6;
			}
			if (y != 0)
			{
				map[x + i][y - 1] = 6;
			}

		}
	}



	//				*** ASSIGNING SHIPS VERTICALLY *** (end)

}
bool check_ship_size(int ship_size)
{

	if (ship_size < 5 && ship_size>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void rotate(int map[][10], int x, int y, int size, char choice)
{

	if (choice == '1')
	{
		if (y == 9 && size > 1)
		{
			y -= size - 1;

		}
		if (y == 8 && size > 2)
		{
			y -= size - 2;

		}
		if (y == 7 && size > 3)
		{
			y -= size - 3;


		}


		for (int i = 0; i < size; i++)
		{

			map[x][y + i] = 0;
			if (y + size <= 9)
			{
				map[x][y + size] = 0;
			}
			if (y + size <= 9 && x != 0)
			{
				map[x - 1][y + size] = 0;
			}
			if (y + size <= 9 && x != 9)
			{
				map[x + 1][y + size] = 0;
			}
			if (y != 0)
			{
				map[x][y - 1] = 0;
			}
			if (y != 0 && x != 0)
			{
				map[x - 1][y - 1] = 0;
			}
			if (y != 0 && x != 9)
			{
				map[x + 1][y - 1] = 0;
			}
			if (x != 9)
			{
				map[x + 1][y + i] = 0;
			}
			if (x != 0)
			{
				map[x - 1][y + i] = 0;
			}
		}
	}


	else if (choice == '2')
	{


	}

}