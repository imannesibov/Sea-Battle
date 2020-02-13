#include"seabat.h"

int main()
{
	srand(time(NULL));
	//PlaySound(TEXT("explosion.wav"), NULL, SND_SYNC);
	bool check = 1;
	bool hide = 1;//hide||show computer's ships
	bool show = 0;//shows computer's map or not
	bool pl_trn = 0;//players' turn
	int min = 97, max = 106;
	int s_coorx = 0;//save coordinate
	int s_coory = 0;//save coordinate	
	int x = 0;
	int y = 0;
	int C = 0;
	bool _ifs2ru = 0;

	bool select=0;
	int snd_nmb = 9;//sound number	
	bool PlayAgain = 1;
	char choice = NULL;
	char s_choice = NULL;//save choice value
	map_args player;
	map_args computer;
	int pl_count = 0;//for player's winnning
	int c_count = 0;//for computer's winning
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


	//LOADING SCREEN
	/*for (int i = 1; i <= 100; i++)
	{

		cout << "\n\n\n\n\n\n\t\t\t\t\t";
		cout << "LOADING...\n\t\t\t\t\t  ";
		cout << i << "%";
		cls
	}*/
	//  LOADING SCREEN 
	
//			*****************		PLACING (START)
	while (true)
	{
		show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);
		cout << "choice placing method: 1)auto 2)manual";
		choice = _getch();

		if (choice == '1')
		{

			while (PlayAgain)
			{

			show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

				if (C > 0)
				{
					cout << "1)Auto 2)back 3)Battle !";
					choice = _getch();
				}

				if (choice == '1')
				{
					
					res_map(player.map);
					res_map(computer.map);
					auto_place(player.map, &player.ship_s1, &player.ship_s2, &player.ship_s3, &player.ship_s4);
					C += 1;
					continue;
				}
				if (choice == '2')
				{
					res_map(player.map);
					res_map(computer.map);
					player.ship_s1 = 0;
					player.ship_s2 = 0;
					player.ship_s3 = 0;
					player.ship_s4 = 0;
					C = 0;
					break;
				}
				if (choice == '3')
				{
					show = 1;
					C = 0;
					PlayAgain = 0;
					auto_place(computer.map, &computer.ship_s1, &computer.ship_s2, &computer.ship_s3, &computer.ship_s4);
					break;
				}
				else
				{
					continue;
				}

			}
			if (choice == '2')
			{
				continue;
			}
		}
//				***************************    ASSIGNING SHIPS MANUALLY(down)
		else if (choice == '2')
		{
			while (true)
			{
				
				show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);
				
				
				if (player.ship_s1 == 4 && player.ship_s2 == 3 && player.ship_s3 == 2 && player.ship_s4 == 1)
				{
					 
					cout << "1)back  2)Battle !";
					choice = _getch();
					 
					if (choice == '1')
					{

						PlayAgain = 1;
						res_map(player.map);
						player.ship_s1 = 0;
						player.ship_s2 = 0;
						player.ship_s3 = 0;
						player.ship_s4 = 0;
						break;
					}
					if (choice == '2')
					{
						auto_place(computer.map, &computer.ship_s1, &computer.ship_s2, &computer.ship_s3, &computer.ship_s4);
						show = 1;
						C = 0;
						PlayAgain = 0;
						break;
					}
				}
				cout << "\nEnter coordinate  : ";
				cin >> player.letter;

				if (player.letter > 64 && player.letter < 75)
				{
					player.letter += 32;
				}

				cin >> player.numb;
				cout << "enter ship size: ";
				cin >> player.ship_size;
				check=check_ship_size(player.ship_size);
				while (!check)
				{
					cls
					show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

					cout << "there are no this sized ships\n";
					cout << "enter ship size again: ";
					cin >> player.ship_size;
					check = check_ship_size(player.ship_size);
						
				}
				while (player.ship_s1==4 && player.ship_size == 1)
				{
					cls
					show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

					cout << "You used all this sized ships use another sized ship\n";
					cout << "enter ship size: ";
					cin >> player.ship_size;
				}
				while (player.ship_s2 == 3&& player.ship_size==2)
				{
					cls
					show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

					cout << "You used all this sized ships use another sized ship\n";
					cout << "enter ship size: ";
					cin >> player.ship_size;
				}
				while (player.ship_s3 == 2 && player.ship_size == 3)
				{
					cls
					show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

					cout << "You used all this sized ships use another sized ship\n";
					cout << "enter ship size: ";
					cin >> player.ship_size;
				}
				while (player.ship_s4 == 1 && player.ship_size == 4)
				{
					cls
					show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);

					cout << "You used all this sized ships use another sized ship\n";
					cout << "enter ship size: ";
					cin >> player.ship_size;
				}
				//check_ships_around(player.map, player.letter - 97, player.numb, select, player.ship_size);
				if (player.ship_size>1)
				{
					cout << "1)place horizontally 2)place vertically";
					choice = _getch();
				}
				else
				{
					choice = '1';
				}			
				if (choice=='1')
				{
					select = 0;
				}
				else if(choice == '2')
				{
					select = 1;
				}
				
				/*if (choice=='1')
				{
					/*if (player.letter - 97 == 9 && player.ship_size > 1)
					{
						player.letter -= player.ship_size - 1;
					}
					if (player.letter - 97 == 8 && player.ship_size > 2)
					{
						player.letter -= player.ship_size - 2;

					}
					if (player.letter - 97 == 7 && player.ship_size > 3)
					{
						player.letter -= player.ship_size - 3;

					}
				}
				else if (choice == '2')
				{

				}*/


				select=check_ships_around(player.map, player.letter - 97, player.numb, select, player.ship_size);
				
				if (!select)
				{
					cout << "\nYou can not use this coordinate\n";
					_getch();
					continue;
				}
				
				manual_place(player.map, player.ship_size,player.letter-97,player.numb, &player.ship_s1, &player.ship_s2, &player.ship_s3, &player.ship_s4,choice,&select);
				
				
				/*if (!select)
				{
					cout << "there is a ship\n";
					continue;
				}*/
			}
		}
//				***************************    ASSIGNING SHIPS MANUALLY(up)
		else
		{

			continue;
		}
		if (PlayAgain)
		{
			continue;
		}
		
		 
	
	

	//			*****************		GAME (START)
	c_count = 0;
	pl_count = 0;
	while (true)
	{
		show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);
		SetConsoleTextAttribute(h, 7);

		if (snd_nmb == 0)
		{
		//	 PlaySound(TEXT("WaterSplash.wav"), NULL, SND_SYNC);

		}
		if (snd_nmb == 1)
		{
		//	 PlaySound(TEXT("explosion.wav"), NULL, SND_SYNC);
		}
		if (pl_count == 20)
		{
		//	PlaySound(TEXT("Victory.wav"), NULL, SND_SYNC);
			cout << "you win!!!...";
			cout << "1)Play again 2)exit";
			choice = _getch();
			if (choice == '2')
			{
				exit(0);

			}
			if (choice == '1')
			{
				PlayAgain = 1;
				res_map(computer.map);
				res_map(player.map);
				pl_count = 0;
				c_count = 0;
				show = 0;			
				break;
			}
		}	
		if (c_count == 20)
		{
				cls
				show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);
				player.ship_s1 = 0;
				player.ship_s2 = 0;
				player.ship_s3 = 0;
				player.ship_s4 = 0;

				cout << "computer win!!!...";
	 		//	PlaySound(TEXT("Victory.wav"), NULL, SND_SYNC);
				cout << "1)Play again 2)exit";
				choice = _getch();
				if (choice == '2')
				{
					exit(0);

				}
				if (choice == '1')
				{
					PlayAgain = 1;
					res_map(computer.map);
					res_map(player.map);
					pl_count = 0;
					c_count = 0;
					show = 0;
					break;

				}
		
		}
		
//					**************   PLAYER'S TURN
 
		if (!pl_trn)		 
		{
			cout << "\nEnter coordinate  : ";
			cin >> player.letter;

			if (player.letter > 64 && player.letter < 75)
			{
				player.letter += 32;
			}

			cin >> player.numb;
			while (computer.map[player.letter - 97][player.numb] == 2 || computer.map[player.letter - 97][player.numb] == 3 || computer.map[player.letter - 97][player.numb] == 4 || computer.map[player.letter - 97][player.numb] == 5)
			{
				cls
				show_map(player.map, computer.map, player.map_size, player.ship_s1, player.ship_s2, player.ship_s3, player.ship_s4, player.letter, player.numb, show);
				if (computer.map[player.letter - 97][player.numb] == 2 || computer.map[player.letter - 97][player.numb] == 3)
				{
					cout << "This coordinate previously used...";
				}
				if (computer.map[player.letter - 97][player.numb] == 4)
				{
					cout << "this is the destroyed ship ...";
				}
				if (computer.map[player.letter - 97][player.numb] == 5)
				{
					cout << "around of  destroyed ship...";
				}
				cout << "\nEnter coordinate  : ";
				cin >> player.letter;

				if (player.letter > 64 && player.letter < 75)
				{
					player.letter += 32;
				}


				cin >> player.numb;
			}
			player_turn(computer.map, player.letter - 97, player.numb, &snd_nmb);

			if (computer.map[player.letter - 97][player.numb] == 3 || computer.map[player.letter - 97][player.numb] == 4)
			{
				pl_trn = 0;
				pl_count++;
			}
			else
			{
				pl_trn = 1;
			}
		}
//					**************   COMPUTER'S TURN
		else 
		{


			x = rand() % 10;
			y = rand() % 10;

			while (player.map[x][y] != 1 || player.map[x][y] != 0) 
			{
				x = rand() % 10;
				y = rand() % 10;
			
				if (player.map[x][y] == 1 || player.map[x][y] != 0) 
				{

					break;
				}
			}
			 
			
			player_turn(player.map, x, y, &snd_nmb);
			if (player.map[x][y] == 3)
			{
				s_coorx = x;
				s_coory = y;

			}
			if (player.map[x][y] == 3 || player.map[x][y] == 4)
			{
				pl_trn = 1;
		
				c_count++;
			}
			else
			{
				pl_trn = 0;
			}
		}

	}
	//			*****************		GAME (END)

	if (PlayAgain)
	{
		continue;
	}

	}
	//			*****************		PLACING (END)

	return 0;
}

