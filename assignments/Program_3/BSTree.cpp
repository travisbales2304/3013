#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bsTree.h"

//http://www.webgraphviz.com/

using namespace std;

int BSTree::count(bstnode *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}

void BSTree::insert(bstnode *&root, bstnode *&temp)
{
	if (!root)
	{
		root = temp;
	}
	else
	{
		if (temp->data < root->data)
		{
			insert(root->left, temp);
		}
		else
		{
			insert(root->right, temp);
		}
	}
}

void BSTree::print_bstnode(bstnode *n, string label = "")
{
	if (label != "")
	{
		cout << "[" << label << "]";
	}
	cout << "[[" << n << "][" << n->data << "]]\n";
	if (n->left)
	{
		cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[L][null]\n";
	}
	if (n->right)
	{
		cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[R][null]\n";
	}
}

bstnode *BSTree::minValuebstnode(bstnode *root)
{
	bstnode *current = root;

	if (root->right)
	{
		current = root->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
	}
	else if (root->left)
	{
		current = root->left;
		while (current->right != NULL)
		{
			current = current->right;
		}
	}

	return current;
}

bstnode *BSTree::deletebstnode(bstnode *&root, string key)
{
	if (!root)
	{
		return NULL;
	}
	if (key < root->data)
	{
		cout << "going left" << endl;
		root->left = deletebstnode(root->left, key);
	}
	else if (key > root->data)
	{
		cout << "going right" << endl;
		root->right = deletebstnode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			bstnode *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			bstnode *temp = root->left;
			delete root;
			return temp;
		}

		// bstnode with two children: Get the inorder successor (smallest
		// in the right subtree)
		bstnode *temp = minValuebstnode(root);

		print_bstnode(temp, "minvaluebstnode");

		// Copy the inorder successor's content to this bstnode
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deletebstnode(root->right, temp->data);
	}
	return root;
}

int BSTree::height(bstnode *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		int left = height(root->left);
		int right = height(root->right);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

void BSTree::printGivenLevel(bstnode *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		print_bstnode(root);
	}
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

void BSTree::GraphVizGetIds(bstnode *bstnodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (bstnodePtr)
	{
		GraphVizGetIds(bstnodePtr->left, VizOut);
		VizOut << "bstnode" << bstnodePtr->data
			<< "[label=\"" << bstnodePtr->data << "\\n"
			//<<"Add:"<<bstnodePtr<<"\\n"
			//<<"Par:"<<bstnodePtr->parent<<"\\n"
			//<<"Rt:"<<bstnodePtr->right<<"\\n"
			//<<"Lt:"<<bstnodePtr->left<<"\\n"
			<< "\"]" << endl;
		if (!bstnodePtr->left)
		{
			NullCount++;
			VizOut << "nbstnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
		GraphVizGetIds(bstnodePtr->right, VizOut);
		if (!bstnodePtr->right)
		{
			NullCount++;
			VizOut << "nbstnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
	}
}

void BSTree::GraphVizMakeConnections(bstnode *bstnodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (bstnodePtr)
	{
		GraphVizMakeConnections(bstnodePtr->left, VizOut);
		if (bstnodePtr->left)
			VizOut << "bstnode" << bstnodePtr->data << "->"
			<< "bstnode" << bstnodePtr->left->data << endl;
		else
		{
			NullCount++;
			VizOut << "bstnode" << bstnodePtr->data << "->"
				<< "nbstnode" << NullCount << endl;
		}

		if (bstnodePtr->right)
			VizOut << "bstnode" << bstnodePtr->data << "->"
			<< "bstnode" << bstnodePtr->right->data << endl;
		else
		{
			NullCount++;
			VizOut << "bstnode" << bstnodePtr->data << "->"
				<< "nbstnode" << NullCount << endl;
		}

		GraphVizMakeConnections(bstnodePtr->right, VizOut);
	}
}

BSTree::BSTree()
{
	root = NULL;
}
BSTree::~BSTree()
{
}

int BSTree::count()
{
	return count(root);
}

void BSTree::insert(string x)
{
	bstnode *temp = new bstnode(x);
	insert(root, temp);
}

void BSTree::deletebstnode(string key)
{
	deletebstnode(root, key);
}

void BSTree::minValue()
{
	print_bstnode(minValuebstnode(root), "minVal");
}

int BSTree::search(string word)
{
	bstnode *nodePtr = root;
	int comparison = 0;

	while (nodePtr) {
		if (nodePtr->data == word)
			return 1;
		else if (word < nodePtr->data)
		{
			nodePtr = nodePtr->left;
			comparison++;
		}
		else
		{
			nodePtr = nodePtr->right;
			comparison++;
		}
	}
	return comparison;
}

int BSTree::height(string key = "")
{
	if (key != "")
	{
		//find bstnode
	}
	else
	{
		return height(root);
	}
	return 0;
}

string BSTree::top()
{
	if (root)
		return root->data;
	else
		return 0;
}

/* Function to line by line print level order travesrsal a tree*/
void BSTree::printLevelOrder()
{
	cout << "Begin Level Order===================\n";
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		cout << "\n";
	}
	cout << "End Level Order===================\n";
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename);
	VizOut << "Digraph G {\n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}\n";
	VizOut.close();
}
