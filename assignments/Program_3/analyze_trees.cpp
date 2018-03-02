#include<iostream>
#include<fstream>
#include<string>
#include "windows.h"
#include "AVLtree.h"
#include "bsTree.h"

using namespace std;

ifstream infile;
ofstream outfile;

void loadlists(string nouns[], string adjectives[], string adverbs[], string animals[], string verbs[]);

int main()
{
	string *nouns = new string[50000];
	string *adjectives = new string[10000];
	string *adverbs = new string[3000];
	string *animals = new string[5000];
	string *verbs = new string[12000];
	loadlists(nouns, adjectives, adverbs, animals, verbs);
	avlTree a;
	BSTree b;

	for (int x = 0; x < 10000; x++)
	{
		if (adjectives[x] == " ")
		{
			x = 10000;
		}
		else if (adjectives[x] != " ")
		{
			a.insert(adjectives[x]);
		}
		cout << "1/10" << endl;
	}
	for (int x = 0; x < 50000; x++)
	{
		if (nouns[x] == " ")
		{
			x = 50000;
		}
		else if (nouns[x] != " ")
		{
			a.insert(nouns[x]);
		}
		cout << "2/10" << endl;
	}
	for (int x = 0; x < 12000; x++)
	{
		if (verbs[x] == " ")
		{
			x = 12000;
		}
		else if (verbs[x] != " ")
		{
			a.insert(verbs[x]);
		}
		cout << "3/10" << endl;
	}
	for (int x = 0; x < 3000; x++)
	{
		if (adverbs[x] == " ")
		{
			x = 3000;
		}
		else if (adverbs[x] != " ")
		{
			a.insert(adverbs[x]);
		}
		cout << "4/10" << endl;
	}
	for (int x = 0; x < 5000; x++)
	{
		if (animals[x] == " ")
		{
			x = 5000;
		}
		else if (animals[x] != " ")
		{
			a.insert(animals[x]);
		}
		cout << "5/10" << endl;
	}


	for (int x = 0; x < 10000; x++)
	{
		if (adjectives[x] == " ")
		{
			x = 10000;
		}
		else if (adjectives[x] != " ")
		{
			b.insert(adjectives[x]);
		}
		cout << "6/10" << endl;
	}
	for (int x = 0; x < 50000; x++)
	{
		if (nouns[x] == " ")
		{
			x = 50000;
		}
		else if (nouns[x] != " ")
		{
			b.insert(nouns[x]);
		}
		cout << "7/10" << endl;
	}
	for (int x = 0; x < 12000; x++)
	{
		if (verbs[x] == " ")
		{
			x = 12000;
		}
		else if (verbs[x] != " ")
		{
			b.insert(verbs[x]);
		}
		cout << "8/10" << endl;
	}
	for (int x = 0; x < 3000; x++)
	{
		if (adverbs[x] == " ")
		{
			x = 3000;
		}
		else if (adverbs[x] != " ")
		{
			b.insert(adverbs[x]);
		}
		cout << "9/10" << endl;
	}
	for (int x = 0; x < 5000; x++)
	{
		if (animals[x] == " ")
		{
			x = 5000;
		}
		else if (animals[x] != " ")
		{
			b.insert(animals[x]);
		}
		cout << "10/10" << endl;
	}

	string data[5];
	infile.open("numofwords.txt");
	for (int x = 0; x < 5; x++)
	{
		infile >> data[x];
	}
	infile.close();

	infile.open("tenthousandwords.txt");

	int avlcomps = 0;
	string word;

	while (infile)
	{
		infile >> word;
		avlcomps += a.search(word);
		cout << "in avl tree" << endl;
	}
	outfile << "AVL Comparisons: " << avlcomps << endl;


	int bstcomps = 0;
	string word2;
	while (infile)
	{
		infile >> word2;
		bstcomps += b.search(word2);
		cout << "in BST tree" << endl;
	}
	infile.close();

	outfile << "BST Comparisons: " << bstcomps << endl;
	



}

void loadlists(string nouns[], string adjectives[], string adverbs[], string animals[], string verbs[])
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

	cout << "removed doubles 1/5" << endl;

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
	cout << "removed doubles 2/5" << endl;

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
	cout << "removed doubles 3/5" << endl;

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
	cout << "removed doubles 4/5" << endl;

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
	cout << "removed doubles 5/5" << endl;
}
