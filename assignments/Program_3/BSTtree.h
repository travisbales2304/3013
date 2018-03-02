#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//http://www.webgraphviz.com/

using namespace std;

struct bstnode
{
	string data;
	bstnode *left;
	bstnode *right;
	bstnode()
	{
		data = "";
		left = NULL;
		right = NULL;
	}
	bstnode(string w)
	{
		data = w;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	bstnode * root;

	int count(bstnode *root);

	void insert(bstnode *&root, bstnode *&temp);

	void print_bstnode(bstnode *, string);

	/**
	* type = ['predecessor','successor']
	*/
	bstnode *minValuebstnode(bstnode *root);

	bstnode *deletebstnode(bstnode *&root, string key);

	int height(bstnode *root);

	/* Print bstnodes at a given level */
	void printGivenLevel(bstnode *root, int level);
	//************************************************************************
	// Method to help create GraphViz code so the expression tree can
	// be visualized. This method prints out all the unique bstnode id's
	// by traversing the tree.
	// Recivies a bstnode pointer to root and performs a simple recursive
	// tree traversal.
	//************************************************************************
	void GraphVizGetIds(bstnode *bstnodePtr, ofstream &VizOut);

	//************************************************************************
	// This method is partnered with the above method, but on this pass it
	// writes out the actual data from each bstnode.
	// Don't worry about what this method and the above method do, just
	// use the output as your told:)
	//************************************************************************
	void GraphVizMakeConnections(bstnode *bstnodePtr, ofstream &VizOut);

public:
	BSTree();
	~BSTree();

	int count();

	void insert(string x);

	void deletebstnode(string key);

	void minValue();

	int search(string);

	int height(string);

	string top();

	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder();

	//************************************************************************
	// Recieves a filename to place the GraphViz data into.
	// It then calls the above two graphviz methods to create a data file
	// that can be used to visualize your expression tree.
	//************************************************************************
	void GraphVizOut(string filename);
};
