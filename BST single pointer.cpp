// BST single pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node { int value; struct node* left; struct node* right; };
struct node* root = NULL;


node* insert(struct node* tree, int value);
void insertD(struct node** tree, int value);
void inorder(struct node* root);


int main()
{


	int x = 0, y;

	do
	{


		cout << "0 Insert int" << endl;
		cout << "1 print tree" << endl;
		cout << "2 terminate int" << endl;
		cout << "3 most common int" << endl;
		cout << "4 largest int" << endl;
		cout << "5 sum " << endl;
		cout << "6 exit" << endl;

		cin >> x;

		//cout << x;

		switch (x)
		{
		case 0:
			cout << "enter element to enter " << endl;
			cin >> y;
			insert(root, y);
			//insertD(&root, y);
			break;

		case 1:
			cout << "printed List" << endl;
			inorder(root);
			break;

		case 6:
			return 0;

		default:
			break;
		}

	} while (x < 6);

}


void insertD(struct node** tree, int value)
{

	// 50 , 40 ,30 , 60 , 45;

	if (*tree == NULL)
	{
		node* newNode = new node;

		newNode->value = value;
		newNode->left = *tree;
		newNode->right = NULL;

		*tree = newNode;

		//*tree = new node{ value, new node{NULL,NULL,NULL},new node{NULL,NULL,NULL} };
		//*tree->left 	
	}


	else if ((*tree)->value > value)
	{
		insert((*tree)->left, value);
	}
	else if ((*tree)->value < value)
	{
		insert((*tree)->right, value);
	}

}

void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << endl << root->value;
		inorder(root->right);
	}
}








node* insert(struct node* tree, int value)
{

	// 50 , 40 ,30 , 60 , 45;

	if (!tree)
	{
		tree = new node{ value,NULL,NULL };
	}


	if (tree->value > value)
	{
		tree->left = insert(tree->left, value);
	}
	else if (tree->value < value)
	{
		tree->right = insert(tree->right, value);
	}

	return tree;

}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
