#include<iostream>
#include<fstream>
#include<string>
#include "windows.h"


using namespace std;


ifstream infile;
ofstream outfile;

string adjectives();
string nouns();
void createword();
string adverbs();
string verbs();
string animals();


int main()
{

	
	


}

void createword()
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
		case 0:
		{
			adjectives(); 
			adjectives(); 
			nouns();

		break;
		}
		case 1: nan();
			break;
		case 2: an();
			break;
		case 3: aavn();
			break;
		case 4: navn();
			break;
		}
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
