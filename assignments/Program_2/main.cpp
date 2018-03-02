#include<iostream>
#include<fstream>
#include<string>
#include "windows.h"


using namespace std;


ifstream infile;
ofstream outfile;

void createwords();
string adjectives();
string nouns();
string adverbs();
string verbs();
string animals();
void loadlists(string nouns[], string adjectives[], string adverbs[], string animals[], string verbs[]);
void loadBST(string adjectives[], string nouns[], string verbs[], string adverbs[], string animals[],string BST[]);



int main()
{
	string *nouns = new string[50000];
	string *adjectives = new string[10000];
	string *adverbs = new string[3000];
	string *animals = new string[5000];
	string *verbs = new string[12000];
	string *BST = new string[100000];


	loadlists(nouns,adjectives,adverbs,animals,verbs);
	loadBST(adjectives, nouns, verbs, adverbs, animals, BST);

	delete[] nouns;
	delete[] adjectives;
	delete[] adverbs;
	delete[] animals;
	delete[] verbs;
}

void createwords()
{
	int choice = 0, counter = 0,numtocreate = 100;
	// Adjective adjective noin
	//noun adjecting noun
	//adjective noun
	//3-5 word parts
	outfile.open("tenthousandwords.txt");
	
	while (counter < numtocreate)
	{
		choice = rand() % 5;
		switch (choice)
		{
		case 0: outfile << adjectives() << " " << adjectives() << " " << nouns() << endl;
			break;
		case 1: outfile << nouns() << " " << adjectives() << " " << nouns() << endl;
			break;
		case 2: outfile << adjectives() << " " << verbs() << " " << nouns() << endl;
			break;
		case 3: outfile << adjectives() << " " << adverbs() << " " << verbs() << " " << animals() << endl;
			break;
		case 4: outfile << adjectives() << " " << adjectives() << " " << adverbs() << " " << verbs() << " " << animals() << endl;
			break;
		}
		counter++;
	}
	outfile.close();
}
string adjectives()
{
	int counter = 0;
	string word = "";
	infile.open("adjectives.txt");
	while (counter != (rand() * rand()) % 15570)
	{
		infile >> word;
	}
	infile.close();
	return word;
}
string adverbs()
{
	int counter = 0;
	string word = "";
	infile.open("adverbs.txt");
	while (counter != (rand() * rand()) % 3236)
	{
		infile >> word;
	}
	infile.close();
	return word;
}
string nouns()
{
	int counter = 0;
	string word = "";
	infile.open("nouns.txt");
	while (counter != (rand() * rand()) % 53737)
	{
		infile >> word;
	}
	infile.close();
	return word;
}
string verbs()
{
	int counter = 0;
	string word = "";
	infile.open("verbs.txt");
	while (counter != (rand() * rand()) % 12018)
	{
		infile >> word;
	}
	infile.close();
	return word;
}
string animals()
{
	int counter = 0;
	string word = "";
	infile.open("animals.txt");
	while (counter != (rand() * rand()) % 2996)
	{
		infile >> word;
	}
	infile.close();
	return word;
}
void loadlists(string nouns[], string adjectives[], string adverbs[], string animals[],string verbs[])
{
	infile.open("nouns.txt");
	for (int x = 0; x < 50000; x++)
	{
		nouns[x] = " ";
	}

	infile >> nouns[0];
	string temp = " ";
	while (infile)
	{
		infile >> temp;
		for (int x = 0; x < 50000; x++)
		{
			if (temp == nouns[x])
			{
				//cout << temp << endl;
				x = 50000;
			}
			if (nouns[x] == " ")
			{
				nouns[x] = temp;
				x = 50000;
			}
		}
	}
	infile.close();

	infile.open("adjectives.txt");
	for (int x = 0; x < 10000; x++)
	{
		adjectives[x] = " ";
	}
	infile >> adjectives[0];
	 temp = " ";
	while (infile)
	{
		infile >> temp;
		for (int x = 0; x < 10000; x++)
		{
			if (temp == adjectives[x])
			{
				//cout << temp << endl;
				x = 10000;
			}
			if (adjectives[x] == " ")
			{
				nouns[x] = temp;
				x = 10000;
			}
		}
	}
	infile.close();

	infile.open("adverbs.txt");
	for (int x = 0; x < 3000; x++)
	{
		adverbs[x] = " ";
	}
	infile >> adverbs[0];
	 temp = " ";
	while (infile)
	{
		infile >> temp;
		for (int x = 0; x < 3000; x++)
		{
			if (temp == adverbs[x])
			{
				//cout << temp << endl;
				x = 3000;
			}
			if (adverbs[x] == " ")
			{
				adverbs[x] = temp;
				x = 3000;
			}
		}
	}
	infile.close();

	infile.open("animals.txt");
	for (int x = 0; x < 5000; x++)
	{
		animals[x] = " ";
	}
	infile >> animals[0];
	 temp = " ";
	while (infile)
	{
		infile >> temp;
		for (int x = 0; x < 5000; x++)
		{
			if (temp == animals[x])
			{
				//cout << temp << endl;
				x = 5000;
			}
			if (animals[x] == " ")
			{
				animals[x] = temp;
				x = 5000;
			}
		}
	}
	infile.close();

	infile.open("verbs.txt");
	for (int x = 0; x < 12000; x++)
	{
		verbs[x] = " ";
	}
	infile >> verbs[0];
	 temp = " ";
	while (infile)
	{
		infile >> temp;
		for (int x = 0; x < 12000; x++)
		{
			if (temp == verbs[x])
			{
				//cout << temp << endl;
				x = 12000;
			}
			if (verbs[x] == " ")
			{
				verbs[x] = temp;
				x = 12000;
			}
		}
	}
	infile.close();
}
void loadBST(string adjectives[],string nouns[],string verbs[],string adverbs[],string animals[],string BST[])
{
	BST[0] = adjectives[0];
	for (int x = 1; x < 10000; x++)
	{
		for (int z = 0; z < 100000; z++)
		{
			if (adjectives[x] < BST[z])
			{
				z = ((z + 1) * 2) - 1;
				if (BST[z] == " ")
				{
				BST[z] = adjectives[x];
				}
			}
			else if (adjectives[x] > BST[z])
			{
				z = ((z + 1) * 2);
				if (BST[z] == " ")
				{
					BST[z] = adjectives[x];
				}
			}
			z--;
		}
	}

	for (int x = 0; x < 100000; x++)
	{
		if (BST[x] == " ")
		{
			x = 100000;
		}
		else if (BST[x] != " ")
		{
			cout << BST[x] << endl;
		}
	}
}
