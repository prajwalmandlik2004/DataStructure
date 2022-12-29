#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

struct students
{
    int Roll_No;
    string Name, Adress;
    string Div;
};

void createFile()
{

    fstream file;
    file.open("main.txt", ios::out);
    if (!file)
    {
        cout << "File is already exist !" << endl;
    }
    else
    {
        cout << "File is created !" << endl;
    }

    file.close();
}

void getData(struct students s[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        cout << "Enter the data of the " << i + 1 << " student !" << endl;
        cout << "\n";
        cout << "Enter the name : ";
        cin >> s[i].Name;
        cout << "Enter the roll no : ";
        cin >> s[i].Roll_No;
        cout << "Enter the adress : ";
        cin >> s[i].Adress;
        cout << "Enter the division : ";
        cin >> s[i].Div;
    }
}

void writeData(struct students s[], int n)
{
    ofstream obj;
    obj.open("main.txt");
    getData(s, n);
    obj << "SrNo\t Name\t RollNo\t Adress\t Division \t" << endl;
    for (int i = 0; i < n; i++)
    {
        obj << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].Adress << "\t\t" << s[i].Div << endl;
    }
    obj.close();
}

void display(struct students s[], int n)
{
    cout << "SrNo\t\tName\t\tRollNo\t\tAdress\t\tDivision\t\t" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].Adress << "\t\t" << s[i].Div << endl;
    }
}

void search(struct students s[], int n)
{
    int rollno;
    cout << "Enter the roll no of student to search the data : " << endl;
    cin >> rollno;
    int a = 0;
    cout << "Search is successfull !" << endl;
    cout << "SrNo\t\tName\t\tRollNo\t\tAdress\t\tDivision\t\t" << endl;

    for (int i = 0; i < n; i++)
    {
        if (s[i].Roll_No == rollno)
        {
            a = 1;
            cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].Adress << "\t\t" << s[i].Div << endl;
        }
    }

    if (a == 0)
    {
        cout << "Search is unsuccessfull !" << endl;
    }
}

void readData(struct students s[], int n)
{

    ifstream obj1;
    obj1.open("main.txt");
    display(s, n);
    obj1.close();
}

void deleting(struct students s[], int n)
{

    string name;
    cout << "\nPlease Enter the name of record you want to delete : ";
    cin >> name;
    ofstream temp;
    temp.open("main.txt");
    while (temp.eof() == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].Name != name)
                temp << name << endl;
        }
    }
    cout << "\nThe record with the name " << name << " has been deleted if it existed" << endl;
    temp.close();
    remove("record.txt");
    rename("main.txt", "record.txt");
}

int main()
{
    int n, ch, temp;
    cout << "\n";
    cout << "Enter the number of students : ";
    cin >> n;
    struct students s[n];
    do
    {
        cout << "\n--- !! Enter the choice !! ---\n"
             << endl;
        cout << "1 : Create the new file" << endl;
        cout << "2 : Get the data of the students" << endl;
        cout << "3 : Display the data of students" << endl;
        cout << "4 : Search the data of the students using roll no" << endl;
        cout << "5 : Add the data of more students" << endl;
        cout << "6 : Delete the data of students" << endl;

        cout << "\n";
        cout << "Enter your choice for an operation : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            createFile();
            break;
        case 2:
            writeData(s, n);
            break;
        case 3:
            readData(s, n);
            break;
        case 4:
            search(s, n);
            break;
        case 5:
            writeData(s, n);
            break;
        case 6:
            deleting(s, n);
        }
        cout << "\n";
        cout << "Enter the 1 to continue and 0 to exit : ";
        cin >> temp;

    } while (temp == 1);

    return 0;
}
