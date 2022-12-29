#include<iostream>

using namespace std;

void heapify(int arr[] , int num , int i){
    int largest = i;
    int l = 2*i+1;
    int R = 2*i+2;

    if(l < num && arr[l] > arr[largest]){
        largest = l;
    }
    if(R < num && arr[R] > arr[largest]){
        largest = R;
    }

    if(largest!=i){
        swap(arr[i] , arr[largest]);
        heapify(arr , num , largest);
    }
}

void heapSort(int arr[] , int num){
    for(int i = num/2-1 ; i>=0 ; i--){
        heapify(arr,num,i);
    }
    for(int i = num-1 ; i>0 ;i--){
        swap(arr[0] , arr[i]);
        heapify(arr,i,0);
    }
}


void display(int arr[] , int num){
    for(int i = 0 ; i < num ; i++){
        cout << arr[i] << "\n" ;
    }
}
int main(){

    int arr[] = {8,3,6,1,4,9,12};
    int num = sizeof(arr) / sizeof(arr[0]);
   
    cout << "The elements in the array is : " << endl;
    display(arr,num);
    heapSort(arr,num);
    cout << "The sorted array is : " << endl;
    display(arr,num);

    return 0;
}
