#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *arr;
};

//checking whether stack is empty
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }else return 0;
}

//checking whether stack is full
int isFull(struct stack *s){
    if(s->top== s->size-1){
        return 1;
    }else return 0;
}

//For pushing(inserting) element in stack
void push(struct stack *s,int element){
    if(isFull(s)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        s->top++;
        s->arr[s->top]=element;
    }
}

//For popping(deleting) element from stack
void pop(struct stack *s){
    if(isEmpty(s)){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        s->top--;
    }
}

//For displaying the stack
void display(struct stack *s){
    for(int i=s->top;i>=0;i--){
        cout<<s->arr[i]<<endl;
    }
}

int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=20;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));    

//Trying to pop from empty stack
    pop(s);

//Pushing elements in stack
    push(s,33);
    push(s,45);
    push(s,12);
    push(s,17);
//displaying
    display(s);

//popping elements from stack
    pop(s);
    pop(s);
//displaying
    display(s);
    return 0;
}