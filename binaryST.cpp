#include <iostream>
using namespace std;
struct BinaSearTree
{
    int data;
    struct BinaSearTree *lft, *rgt;
};



struct BinaSearTree *newNode(char data_in)
{
    BinaSearTree *ptr1 = new BinaSearTree();
    ptr1->data = data_in;
    ptr1->lft = ptr1->rgt = NULL;
    return ptr1;
}

void Inorder(struct BinaSearTree *root)
{
    if (root != NULL)
    {
        Inorder(root->lft);
        cout << root->data << " ";
        Inorder(root->rgt);
    }
}
struct BinaSearTree *Insert(struct BinaSearTree *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->lft = Insert(node->lft, key);
    else
        node->rgt = Insert(node->rgt, key);
    return node;
}
struct BinaSearTree *Search(struct BinaSearTree *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return Search(root->rgt, key);
    else
        return Search(root->lft, key);
}
struct BinaSearTree *MinValNode(struct BinaSearTree *node)
{
    struct BinaSearTree *current = node;
    while (current && current->lft != NULL)
        current = current->lft;
    return current;
}
struct BinaSearTree *deleteNode(struct BinaSearTree *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->lft = deleteNode(root->lft, key);
    else if (key > root->data)
        root->rgt = deleteNode(root->rgt, key);
    else
    {
        if (root->lft == NULL)
        {
            struct BinaSearTree *temp = root->rgt;
            free(root);
            return temp;
        }
        else if (root->rgt == NULL)
        {
            struct BinaSearTree *temp = root->lft;
            free(root);
            return temp;
        }
        else
        {
            struct BinaSearTree *temp = MinValNode(root->rgt);
            root->data = temp->data;
            root->rgt = deleteNode(root->rgt, temp->data);
        }
    }
    return root;
}


void Mirror(struct BinaSearTree *node)
{
    if (node == NULL)
        return;
    else
    {
        struct BinaSearTree *ptr2;
        Mirror(node->lft);
        Mirror(node->rgt);
        ptr2 = node->lft;
        node->lft = node->rgt;
        node->rgt = ptr2;
    }
}


struct BinaSearTree *Copy(struct BinaSearTree *root)
{
    BinaSearTree *root2;
    if (root == NULL)
        return NULL;
    root2 = new BinaSearTree;
    root2->lft = Copy(root->lft);
    root2->rgt = Copy(root->rgt);
    root2->data = root->data;
    return root2;
}
int Maxdepth(struct BinaSearTree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int depth1 = Maxdepth(root->lft);
        int depth2 = Maxdepth(root->rgt);
        if (depth1 > depth2)
            return (depth1 + 1);
        else
            return (depth2 + 1);
    }
}


int main()
{
    struct BinaSearTree *root = NULL;
    struct BinaSearTree *root2 = NULL;
    struct BinaSearTree *root1 = NULL;
    struct BinaSearTree *root3 = NULL;
    int ch, n, d, depth;
    while (1)
    {
        cout << "\n"
             << "1.Insert";
        cout << endl
             << "2.Delete";
        cout << endl
             << "3.Search";
        cout << endl
             << "4.Traversal";
        cout << endl
             << "5.Depth of BST";
        cout << endl
             << "6.Copy oF BST";
        cout << endl
             << "7.Mirror Image";
        cout << endl
             << "8.EXIT";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter number of values you want to Insert: ";
            cin >> n;
            cout << "\nEnter values to create BST: ";
            for (int i = 0; i < n; i++)
            {
                cin >> d;
                root = Insert(root, d);
            }
            break;
        case 2:
            cout << "\nEnter the element you want to delete: ";
            cin >> d;
            root3 = deleteNode(root, d);
            break;
        case 3:
            cout << "\nEnter the element to Search: ";
            cin >> d;
            root1 = Search(root, d);
            if (root1 != NULL)
                cout << "\nElement Found";
            else
                cout << "\nElement Not Found";
            break;
        case 4:
            cout << "\nTraversal of BST: ";
            Inorder(root);
            break;
        case 5:
            depth = Maxdepth(root);
            cout << "The depth of BST is: " << depth;
            break;
        case 6:
            root2 = Copy(root);
            cout << "The Copy of BST is: ";
            Inorder(root2);
            break;
        case 7:
            Mirror(root);
            cout << "\nInorder traversal of the Mirror BST is: ";
            Inorder(root);
            Mirror(root);
            break;
        case 8:
            return 0;
        default:
            cout << "\nInvalid Input ";
        }
    }
    return 0;
}

// #include <iostream>

// using namespace std;

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node *createBST(char key)
// {
//     struct node *ptr = new node;
//     ptr->data = key;
//     ptr->left = ptr->right = NULL;
//     return ptr;
// }

// struct node *insert(struct node *newNode, int key)
// {
//     if (newNode == NULL)
//     {
//         return createBST(key);
//     }
//     if (key < newNode->data)
//     {
//         newNode->left = insert(newNode->left, key);
//     }
//     else
//     {
//         newNode->right = insert(newNode->right, key);
//     }

//     return newNode;
// }

// void inorder(struct node *root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         cout << root->data << " ";
//         inorder(root->right);
//     }
// }

// struct node *search(struct node *root, int key)
// {
//     if (root == NULL || root->data == key)
//     {
//         return root;
//     }
//     if (root->data < key)
//     {
//         return search(root->right, key);
//     }
//     else
//     {
//         return search(root->left, key);
//     }
// }

// struct node *mirror(struct node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     else
//     {

//         mirror(root->left);
//         mirror(root->right);
//         swap(root->right, root->left);
//     }
//     return root;
// }

// void displayLN(struct node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         cout << root->data << " ";
//     }
//     if (root->left != NULL)
//     {
//         displayLN(root->left);
//     }
//     if (root->right != NULL)
//     {
//         displayLN(root->right);
//     }
// }

// int depth(struct node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         int depth1 = depth(root->left);
//         int depth2 = depth(root->right);
//         if (depth1 > depth2)
//         {
//             return (depth1 + 1);
//         }
//         else
//         {
//             return (depth2 + 1);
//         }
//     }
// }

// struct node *copy(struct node *root)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     struct node *root1 = new node;
//     root1->left = copy(root->left);
//     root1->right = copy(root->right);
//     root1->data = root->data;
//     return root1;
// }

// int main()
// {

//     int n, key;
//     struct node *root = NULL;
//     struct node *root1 = NULL;
//     struct node *root2 = NULL;
//     struct node *root3 = NULL;
//     cout << "Enter the number of elements in BST : ";
//     cin >> n;
//     cout << "Enter the elements : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> key;
//         root = insert(root, key);
//     }
//     cout << "Data is inserted Successfully !" << endl;
//     cout << "Enter the element you want to search : " << endl;
//     cin >> key;
//     root3 = search(root, key);
//     if (root != NULL)
//     {
//         cout << "Element is Found !" << endl;
//     }
//     else
//     {
//         cout << "Element is not Found !" << endl;
//     }
//     cout << "The inorder is : ";
//     inorder(root);
//     cout << endl;
//     cout << "The depth is : " << endl;
//     int max;
//     max = depth(root);
//     cout << max << endl;
//     cout << "Copy is : " << endl;
//     root2 = copy(root);
//     inorder(root2);
//     cout << endl;
//     cout << "The mirror is : ";
//     inorder(mirror(root));
//     cout << "\n";
//     cout << "The leaf nodes are : ";
//     displayLN(root);

//     return 0;
// }
