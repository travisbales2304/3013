#include<iostream>
#include<fstream>
#include<string>
#include"windows.h"
using namespace std;

ifstream infile;
ofstream outfile;

void createwords();
string adjectives();
string nouns();
string adverbs();
string verbs();
string animals();
int  wnouns = 0, wadjectives = 0, wadverbs = 0, wverbs = 0, wanimals = 0;

int main()
{
	createwords();
}

void createwords()
{
	int choice = 0, counter = 0, numtocreate = 10000;
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
		case 0: 
		{
			wadjectives+=2;
			wnouns++;
			outfile << adjectives() << " " << adjectives() << " " << nouns() << endl;
			break;
		}
		case 1: 
		{
			wnouns += 2;
			wadjectives++;
			outfile << nouns() << " " << adjectives() << " " << nouns() << endl;
			break;
		}
		case 2: 
		{
			wadjectives++;
			wverbs++;
			wnouns++;
			outfile << adjectives() << " " << verbs() << " " << nouns() << endl;
			break;
		}
		case 3: 
		{
			wadjectives++;
			wadverbs++;
			wverbs++;
			wanimals++;
			outfile << adjectives() << " " << adverbs() << " " << verbs() << " " << animals() << endl;
			break;
		}
		case 4: 
		{	
			wadjectives += 2;
			wadverbs++;
			wverbs++;
			wanimals++;
			outfile << adjectives() << " " << adjectives() << " " << adverbs() << " " << verbs() << " " << animals() << endl;
			break;
		}
		}
		counter++;
	}
	outfile.close();
	outfile.open("numofwords.txt");
	outfile << wadjectives << endl << wnouns << endl << wverbs << endl << wadverbs << endl << wanimals << endl;
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
