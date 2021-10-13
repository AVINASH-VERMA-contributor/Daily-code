#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack s){
    if(s.top==-1){
        return 1;
    }else return 0;
}


int main(){
    struct stack s;
    s.size=20;
    s.top=-1;
    s.arr=(int *)malloc(s.size*sizeof(int));

    if(isEmpty(s)){
        cout<<"Stack is empty"<<endl;
    }else cout<<"Stack is not empty"<<endl;
    
    //Inserting one element in stack
    s.arr[0]=5;
    s.top++;


    if(isEmpty(s)){
        cout<<"Stack is empty"<<endl;
    }else cout<<"Stack is not empty"<<endl;


    return 0;
}