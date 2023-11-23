//        INSERTION SORT

// Insertion sort is a famous sorting algorithm that sort a given array
// It works on the principle that it swaps the element of array with its left adjacent
//  element until it reaches its correct position
//    Time complexity-

// The worst-case time complexity of the Insertion sort is O(N^2)
// The average case time complexity of the Insertion sort is O(N^2)
// The time complexity of the best case is O(N).



#include<iostream>
using namespace std;
// function to perform insertion sort
void InsertionSort(int arr[],int n){
for(int i=0;i<n;i++){
    // store the current element of array as it will be updated ahead
    int key=arr[i];
    // create a variable j that just point to one position before i
    int j=i-1;
    // check if value at j th index is greater than at i th index
    // if yes then swap it 
   
    while(arr[j]>key&&j>=0){
    //  if yes then update the value at i with value at j
       arr[j+1]=arr[j];
    //    now since we have swapped the value now we make sure that value at j
    // at new position is greater than its previous 
    j=j-1;
    }
    // assign the next position of j to key now
    arr[j+1]=key;

    }
}
int main(){
int n;
cout<<"Enter the size of array :";
cin>>n;
int arr[n];
cout<<endl;
cout<<"Enter the elements of array :";
for(int i=0;i<n;i++){
    cin>>arr[i];
    cout<<" ";
}
cout<<endl;
cout<<"Array before insertion sort is :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
InsertionSort(arr,n);
cout<<"Array after insertion sort is :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"Insertion sort completed sucessfully";
    return 0;
}
// output of above code is 
// Enter the size of array :5
// Enter the elements of array :1 3 5 2 4     
// Array before insertion sort is :
// 1 3 5 2 4 
// Array after insertion sort is :
// 1 2 3 4 5 
// Insertion sort completed sucessful





