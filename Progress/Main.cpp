#include<iostream>
#include<fstream>
#include<string>
#include "windows.h"

using namespace std;

ifstream infile;
ofstream outfile;


void clicker();

int main()
{
	int menuselect = 0;
	while (menuselect != -1)
	{
		cout << "Luca's" << endl << endl;
		cout << "Menu" << endl << "1.Select" << endl << "2.Change Settings" << endl << "3.Exit" << endl;
		cin >> menuselect;

		if (menuselect == 1)
		{
			while (menuselect != 5)
			{
				menuselect = 0;
				system("cls");
				cout << "1.A" << endl << "2.C" << endl << "3.W" << endl << "4.F" << endl << "5.Previous Menu" << endl;
				cin >> menuselect;
				if (menuselect == 1)
				{
					system("cls");
					clicker();
				}
			}
			
			if (menuselect == 5)
			{
				menuselect = 10;
			}

		}
		else if (menuselect == 2)
		{
			menuselect = 0;
			while (menuselect != 2)
			{
				system("cls");
				cout << "1.Save settings" << endl << "2.Previous Menu" << endl;
				cin >> menuselect;
				if (menuselect == 1)
				{
					system("cls");
					Sleep(1000);
					cout << "Settings Saved" << endl;
					Sleep(1000);
				}
			}
		}
		else if(menuselect == 3)
		{
			menuselect = -1;
		}
		system("cls");
	}




}



void clicker()
{
	int select = 0;
	outfile.open("SavedPoints.dat");
	bool stop = false;
	cout << "Click to save each point." << endl << "Press space to stop saving points" << endl;

	while (!stop)
	{
		
		if (GetKeyState(0x01) < 0)
		{
			POINT cursorPos;
			GetCursorPos(&cursorPos);
			cout << cursorPos.x << " " << cursorPos.y << endl;
			outfile << cursorPos.x << " " << cursorPos.y << endl;
			cout << "Saved" << endl;
			Sleep(200);
		}
		

		
		if (GetKeyState(0x20) < -1)
		{
			cout << "Stopped" << endl;
			stop = true;
			Sleep(1000);
		}
		
		
	}
	outfile.close();


	system("cls");
	int points[2][10] = {};

	while (select != -10)
	{
		system("cls");
		cout << "1.Start" << endl <<"2.Check points" << endl << "3.Delete points" << endl <<"4.Main Menu" << endl;
		cin >> select;
		infile.open("SavedPoints.dat");
		int counter = 0;
		
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				infile >> points[y][x];
			}
			cout << endl;
		}

		if (select == 2)
		{
			system("cls");
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 2; y++)
				{
					cout << points[y][x] << " ";
				}
				cout << endl;
			}
			Sleep(5000);
		}


		if (select == 3)
		{
			system("cls");
			for (int x = 0; x < 10; x++)
			{
				cout << "Point " << x + 1 << " ";
				for (int y = 0; y < 2; y++)
				{
					cout << points[y][x] << " ";
				}
				cout << endl;
			}

			cout << "Which point would you like to delete?" << endl;
			cin >> select;

			switch (select)
			{
			case 1: points[0][0] = 0; points[1][0] = 0;
				break;
			case 2: points[0][1] = 0; points[1][1] = 0;
				break;
			case 3: points[0][2] = 0; points[1][2] = 0;
				break;
			case 4: points[0][3] = 0; points[1][3] = 0;
				break;
			case 5: points[0][4] = 0; points[1][4] = 0;
				break;
			case 6: points[0][5] = 0; points[1][5] = 0;
				break;
			case 7: points[0][6] = 0; points[1][6] = 0;
				break;
			case 8: points[0][7] = 0; points[1][7] = 0;
				break;
			case 9: points[0][8] = 0; points[1][8] = 0;
				break;
			case 10: points[0][9] = 0; points[1][9] = 0;
				break;
			}
			select = 0;
		}

		if (select == 4)
		{
			infile.close();
			return;
		}


	}
}
