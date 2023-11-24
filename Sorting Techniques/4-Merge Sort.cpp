//        INSERTION SORT

//  Merge sort is a famous sorting algorithm that sort a given array
// ->Merge sort is defined as a sorting algorithm that works by dividing an
//    array into smaller subarrays, sorting each subarray, and then merging 
//    the sorted subarrays back together to form the final sorted array.

// ->In simple terms, we can say that the process of merge sort is to divide 
//  the array into two halves, sort each half, and then merge the sorted halves back together.
//   This process is repeated until the entire array is sorted.


//    Time complexity-

// Time Complexity: O(N log(N))  --> for all worst average and best case
//   Merge Sort is a recursive algorithm and time complexity can
//       be expressed as following recurrence relation. 

//    T(n) = 2T(n/2) + θ(n)




#include<iostream>
using namespace std;
// function to merge the the arrays in sorted fashion
void merge(int arr[],int l,int mid,int r){
    // create two array to store two sorted arrays
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;

        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}
// main merge sort function to recursively divide the array
void MergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        // recursively call the mergesort function to divide the array
      MergeSort(arr,l,mid);
      MergeSort(arr,mid+1,r);

// call the merge function to merge the divided array
      merge(arr,l,mid,r);
    }
}
int main(){
int n;
cout<<"Enter the size of array :";
cin>>n;
int arr[n];
cout<<endl;
cout<<"Enter the elements of arrray :";
for(int i=0;i<n;i++){
    cin>>arr[i];
    cout<<" ";
}
cout<<endl;
cout<<"Array before merge sort is :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
MergeSort(arr,0,n-1);
cout<<"Array after merge sort is :"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"Merge sort completed sucessfully";
    return 0;
}
// output of above code is 
// Enter the size of array :5
// Enter the elements of array :1 3 5 2 4     
// Array before merge sort is :
// 1 3 5 2 4 
// Array after merge sort is :
// 1 2 3 4 5 
// Merge sort completed sucessful





