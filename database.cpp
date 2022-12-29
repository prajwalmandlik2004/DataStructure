#include <iostream>
#include<string.h>
using namespace std;

// Using Function

struct Students
{
    string Name;
    int Roll_No;
    float SGPA;
};


// Functions 
void getData(struct Students s[] , int n);
void displayData(struct Students s[] ,int n);
void bubbleSort(struct Students s[], int n);
void insertionSort(struct Students s[], int n);
void searchData(struct Students s[], int n);
int binarySearch(struct Students s[], int n);
void quickSort(struct Students s[], int n , int first ,int last);
void sortData(struct Students s[], int n);
void sortingName(struct Students s[], int n);
void searchName(struct Students s[], int n);

int main()
{
    int n;
    cout << "\n" ;
    cout << "!!!  Enter the number of students !!! : ";
    cin >> n;
    cout << "\n" ;
    struct Students s[n];
    getData(s , n);
    
    int choice , ope;
    int first = 0;
    int last = n-1;
    do{
        cout << "-------------------------------------------------------" << endl;
        cout << "Menu \t\t Operations " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "\n";
        cout << " 1   =>   display the data of the student" << endl;
        cout << " 2   =>   sorting of student data using bubblesort" << endl;
        cout << " 3   =>   sorting of student data using insertion sort" << endl;
        cout << " 4   =>   search the data of the students using linear search" << endl;
        cout << " 5   =>   search the name of the students using binary search" << endl;
        cout << " 6   =>   sort the data of toppers using quick sort" << endl;
        cout << "\n" ;
        cout << "Enter the choice for an operation : ";
        cin >> choice;

    switch(choice){
        case 1:{
            displayData(s,n);
            break;
        }
        case 2:{
            bubbleSort(s,n);
            break;
        }
        case 3:{
            insertionSort(s,n);
            break;
        }
        case 4:{
            searchData(s,n);
            break;
        }
        case 5:{
            binarySearch(s,n);
            searchName(s,n);
            break;
        }
        case 6:{
            quickSort(s,n,first,last);
            sortData(s,n);
            break;
        }
        }
    cout << "\n" ;
    cout << "Enter 0 to exit and 1 to continue : ";
    cin >> ope;
    } while(ope==1);
}

// 01 - To get the data of the students
void getData(struct Students s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        cout << "!!! Enter the data of the " << i + 1 << " student !!!" << endl;
        cout << "\n";
        cout << "Enter the name of the student : ";
        cin >> s[i].Name;
        cout << "Enter the Roll_No of the student : ";
        cin >> s[i].Roll_No;
        cout << "Enter the SGPA of the student : ";
        cin >> s[i].SGPA;
    }
    cout << "\n" ;
}


// 02-To display the data of the student
void displayData(struct Students s[], int n)
{
    cout << "\n" ;
    cout << "-------------------------------------------------------" << endl;
    cout << "The data of the students are given below" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "\n" ;
    cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
    for (int i = 0; i < n; i++)
    {
         cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].SGPA << "\t\t" << endl;
    }
}


// 03-Bubble sort to arrange the data in ascending order according to roll no
void bubbleSort(struct Students s[], int n)
{

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < (n-1); i++)
        {
            if (s[i].Roll_No > s[i + 1].Roll_No)
            {
                Students temp = s[i];
                s[i] = s[i + 1];
                s[i + 1]= temp;
            }
        }
    }
    cout << "\n" ;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "The sorting data of the students according to the roll no is given below" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\n" ;
    cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].SGPA << "\t\t" << endl;
    }
}


// 04-Insertion sort to arrange the data of students alphabetcally using name
void insertionSort(struct Students s[], int n)
{
    string key;
    int roll;
    float sgpa;
    for (int i = 1; i < n; i++)
    {
        key = s[i].Name;
        roll = s[i].Roll_No;
        sgpa = s[i].SGPA;
        int j = i - 1;
        while (j >= 0 && s[j].Name > key)
        {
            s[j + 1].Name = s[j].Name;
            s[j + 1].Roll_No = s[j].Roll_No;
            s[j + 1].SGPA = s[j].SGPA;
            j = j - 1;
        }
        s[j + 1].Name = key;
        s[j + 1].Roll_No = roll;
        s[j + 1].SGPA = sgpa;

    }
    cout << "\n" ;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "The sorting of students data using name is given below" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n" ;
    cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].SGPA << "\t\t" << endl;
        }
}


// 05-Search the data of students using SGPA use Linear search
void searchData(struct Students s[], int n)
{
    float sgpa;
    int b = 0;
    cout << "\n" ;
    cout << "Enter the SGPA of the student : ";
    cin >> sgpa;
    cout << "\n";
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Searching is Successful and his/her data is given below : " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n" ;
    cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
    for (int i = 0; i < n; i++)
    {
        if (s[i].SGPA == sgpa)
        {
            b = 1;
            cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].SGPA << "\t\t" << endl;
        }
    }
    cout << "\n" ;
    if (b == 0)
    {
        cout << "No one got this SGPA" << endl;
    }
}


// 06- Search the name of the student using binary search
int binarySearch(struct Students s[], int n)
{
    sortingName(s,n);
    int low = 0;
    int high = (n-1);
    string key;
    cout<<"Enter the name of the student : ";
    cin>> key;
    while (low<=high)
    {
        int mid = (low + high)/2;
        if((key ==  s[mid].Name))
        {
            return mid;
        }
        if((key > s[mid].Name))
        {
            low = mid + 1;
        }
        if((key < s[mid].Name))
        {
            high = mid - 1;
        }
    }
   return -1;  
}


// Sorting of Name 
void sortingName(struct Students s[], int n)
{
    string key;
    for(int i=1; i<n; i++)
    {
        key =  s[i].Name;
        int j = i-1;
        while (j >= 0 && (s[j].Name > key))
        { 
            Students temp;
            temp = s[j];
            s[j] = s[j+1];
            s[j+1] = temp;
            j = j-1; 
        }
        s[j + 1].Name = key; 
    } 
} 


// Searching of Name 
void searchName(struct Students s[], int n)
{
    int res ;
    if(res == -1)
    {
        cout<<"Searching is not successful";
    }
    else
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "The Searching is successful and data of student is given below" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "\n" ;
        cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
        cout << res + 1 << "\t\t" << s[res].Name << "\t\t" << s[res].Roll_No << "\t\t" << s[res].SGPA << "\t\t" << endl;
    }
} 


// 07 - Sorting of toppers list using quick sort
void quickSort(struct Students s[], int n , int first , int last){
    int p , i , j ;
    struct Students temp;
    p = i = first;
    j = last;
    if(first < last){
        while(i<j){
            while(s[i].SGPA >= s[p].SGPA && i<last){
                i++;
            }
            while(s[j].SGPA < s[p].SGPA){
                j--;
            }
            if(i<j){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            temp = s[j];
            s[j] = s[p];
            s[p] = temp;

            quickSort(s,n,first,j-1);
            quickSort(s,n,j+1,last);
        }
    }
}


// Sort data
void sortData(struct Students s[], int n){
    int num;
    cout << "\n" ;
    cout << "Enter the number of Toppers you want to display : ";
    cin >> num;
    cout << "\n" ;
    cout << "-------------------------------------------------------" << endl;
    cout << "The sorting of student data according to SGPA" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "\n" ;
    cout << "Sr.No\t\tName\t\tRoll_No\t\tSGPA\t" << endl;
    for (int i = 0; i < num; i++)
    {
         cout << i + 1 << "\t\t" << s[i].Name << "\t\t" << s[i].Roll_No << "\t\t" << s[i].SGPA << "\t\t" << endl;
    }
}
