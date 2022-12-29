#include <iostream>
#include <ctype.h>
#include <string.h>
#define max 30
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

char exp[50];
node *a[max];
int top = -1;

node *createETree(char exp[50])
{
    node *temp;
    int i;
    char symbol;

    for (i = 0; exp[i] != '\0'; i++)
    {
        symbol = exp[i];
        temp = new node;
        temp->data = symbol;
        temp->left = NULL;
        temp->right = NULL;
        if (isalnum(symbol))
        {
            a[++top] = temp;
        }
        else
        {
            temp->right = a[top--];
            temp->left = a[top--];

            a[++top] = temp;
        }
    }

    return a[top--];
}

void inorder(node *top)
{
    if (top != NULL)
    {
        inorder(top->left);
        cout << top->data;
        inorder(top->right);
    }
}
void preorder(node *top)
{
    if (top != NULL)
    {
        cout << top->data;
        preorder(top->left);
        preorder(top->right);
    }
}
void NonRpre(node *temp)
{
    int top = -1;
    while (top >= 0 || temp != NULL)
    {
        while (temp != NULL)
        {
            cout << temp->data;
            a[++top] = temp;
            temp = temp->left;
        }
        temp = a[top--];
        temp = temp->right;
    }
}
void NonRin(node *temp)
{
    int top = -1;
    while (top >= 0 || temp != NULL)
    {
        while (temp != NULL)
        {
            a[++top] = temp;
            temp = temp->left;
        }
        temp = a[top--];
        cout << temp->data;
        temp = temp->right;
    }
}
void NonRpost(node *temp)
{
    int top = -1;
    int p, i, I = 0;
    char str[25];
    while (top >= 0 || temp != NULL)
    {
        while (temp != NULL)
        {
            str[I++] = temp->data;
            a[++top] = temp;
            temp = temp->right;
        }
        temp = a[top--];
        temp = temp->left;
    }
    str[I] = '\0';
    p = strlen(str);
    for (i = p; i >= 0; i--)
        cout << str[i];
}
int main()
{
    node *root = NULL;

    cout << "Enter the Postfix Expression : ";
    cin >> exp;
    cout << "\n";

    root = createETree(exp);
    cout << "-------------------------------------------" << endl;
    cout << "Inorder using recursion : ";
    inorder(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\n";
    cout << "-------------------------------------------" << endl;
    cout << "Preorder using recursion : ";
    preorder(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\n";
    cout << "-------------------------------------------" << endl;
    cout << "Inorder using Non-recursion : ";
    NonRin(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\n";
    cout << "-------------------------------------------" << endl;
    cout << "Preorder using Non-recursion : ";
    NonRpre(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\n";
    cout << "-------------------------------------------" << endl;
    cout << "Post order using Non-recursion : ";
    NonRpost(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
}

