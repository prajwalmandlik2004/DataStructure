// Insertion in Threaded Binary Search Tree.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int data;
	bool lthread;
	bool rthread;
};

struct Node *insert(struct Node *root, int key)
{

	Node *ptr = root;
	Node *par = NULL;
	while (ptr != NULL)
	{

		if (key == (ptr->data))
		{
			printf("Duplicate Key !\n");
			return root;
		}

		par = ptr;

		if (key < ptr->data)
		{
			if (ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}

		else
		{
			if (ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}

	Node *tmp = new Node;
	tmp->data = key;
	tmp->lthread = true;
	tmp->rthread = true;

	if (par == NULL)
	{
		root = tmp;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	else if (key < (par->data))
	{
		tmp->left = par->left;
		tmp->right = par;
		par->lthread = false;
		par->left = tmp;
	}
	else
	{
		tmp->left = par;
		tmp->right = par->right;
		par->rthread = false;
		par->right = tmp;
	}

	return root;
}

struct Node *inorderSuccessor(struct Node *ptr)
{

	if (ptr->rthread == true)
		return ptr->right;

	ptr = ptr->right;
	while (ptr->lthread == false)
		ptr = ptr->left;
	return ptr;
}


void inorder(struct Node *root)
{
	if (root == NULL)
		printf("Tree is Empty !\n");

	struct Node *ptr = root;
	while (ptr->lthread == false)
		ptr = ptr->left;

	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = inorderSuccessor(ptr);
	}
}

void preorder(struct Node *root)
{
	if (root == NULL)
	{
		cout << "Tree is Empty !\n";
	}
	else
	{
		while (root != NULL)
		{
			cout << root->data << " ";
			if (root->lthread == false)
			{
				root = root->left;
			}
			else if (root->rthread == false)
			{
				root = root->right;
			}
			else
			{
				while (root != NULL && root->rthread == true)
				{
					root = inorderSuccessor(root);
				}
				if (root != NULL)
				{
					root = root->right;
				}
			}
		}
	}
}

int main()
{
	struct Node *root = NULL;
	int ch, n, temp, key;
	do
	{

		cout << "\nEnter the choice !\n"
			 << endl;
		cout << "1 : Insert the data in TBT" << endl;
		cout << "2 : Inorder Traversal of TBT" << endl;
		cout << "3 : Preorder Traversal of TBT" << endl;
		cout << "\n";
		cout << "Enter your choice : ";
		cin >> ch;
		cout << "\n";
		switch (ch)
		{
		case 1:
			cout << "Enter the count of elements to insert in to the TBT : ";
			cin >> n;
			cout << "Enter the elements : " << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> key;
				root = insert(root, key);
			}
			cout << "Data inserted Successfully !" << endl;
			break;

		case 2:
			cout << "The inorder traversal of the TBT is : ";
			inorder(root);
			break;

		case 3:
			cout << "The preorder traversal of the TBT is : ";
			preorder(root);
			break;
		}

		cout << "\n";
		cout << "Enter 1 to continue and 0 to exit" << endl;
		cin >> temp;
	} while (temp == 1);
	cout << "--- !! End of Program !! ---" << endl;

	return 0;
}
