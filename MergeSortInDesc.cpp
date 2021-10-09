#include<iostream>
using namespace std;


void MergeDesc(int a[],int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int b[r];
    int k=l;
    while(i<=mid && j<=r){
        if(a[i]>a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=r){
            b[k]=a[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }

for(int k=l;k<=r;k++){
    a[k]=b[k];
}

}




void MergeSort(int a[],int l,int r){
  if(l<r){  
    int mid=(l+r)/2;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);
    MergeDesc(a,l,mid,r);
  }
}

int main(){
        int n;
        cout<<"Enter number of elements in the array"<<endl;
        cin>>n;
        int a[n+1];
        cout<<"Enter "<<n<<" elements in the array"<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

MergeSort(a,0,n-1);


        cout<<"After applying merge sort for descending: "<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<endl;
        }

    return 0;
}

