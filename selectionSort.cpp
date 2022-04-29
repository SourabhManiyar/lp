#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements separated by space: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}