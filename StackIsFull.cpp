#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *arr;
};


int isFull(struct stack s){
    if(s.top== s.size-1){
        return 1;
    }else return 0;
}


int main(){
    struct stack s;
    s.size=2;
    s.top=-1;
    s.arr=(int *)malloc(s.size*sizeof(int));

    if(isFull(s)){
        cout<<"Stack is full"<<endl;
    }else cout<<"Stack is not full"<<endl;

//Inserting two elements 
    s.arr[0]=5;
    s.top++;

    s.arr[0]=7;
    s.top++;


    if(isFull(s)){
        cout<<"Stack is full"<<endl;
    }else cout<<"Stack is not full"<<endl;

    return 0;
}