#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n){
    int i,j;
    int temp;

    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1]=temp;
    }
}


int main(){
     int n;
        cout<<"Enter number of elements in the array"<<endl;
        cin>>n;
        int a[n];
        cout<<"Enter "<<n<<" elements in the array"<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        InsertionSort(a,n);

cout<<"After sorting"<<endl;
         for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
}