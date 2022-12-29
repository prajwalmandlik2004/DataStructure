#include <iostream>
#define n 10
using namespace std;

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % n == front)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = x;
        cout << endl;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is full" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << "\nThe deleted element is : " << queue[front] << endl;
        front = (front + 1) % n;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is : ";
        while (i != rear+1)
        {
            cout << queue[i] << " ";
            i = (i + 1) % n;
        }
    }
}

int main()
{
    int choice, ope, num , x;
    do
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Menu \t\t Operations " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "\n";
        cout << " 1   =>   Insert the elements in circular queue" << endl;
        cout << " 2   =>   Display the circular queue" << endl;
        cout << " 3   =>   Dequeue the elements in circular queue" << endl;
        cout << "\n";
        cout << "Enter the choice for an operation : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            enqueue(1);
            enqueue(7);
            enqueue(2);
            enqueue(3);
            enqueue(8);
            enqueue(4);
            enqueue(12);
            enqueue(15);
            cout << "Elements inserted successfully !" << endl;
            cout << "After insertion the ";
            display();
            cout << endl;
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            dequeue();
            break;
        }
        }
        cout << "\n";
        cout << "Enter 0 to exit and 1 to continue : ";
        cin >> ope;
    } while (ope == 1);

    return 0;
}
