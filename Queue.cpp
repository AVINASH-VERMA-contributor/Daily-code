#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int element){
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=element;
    }
}

void dequeue(struct queue *q){
    if(isEmpty(q)){
        cout<<"Queue Underflwow"<<endl;
    }
    else{
        q->f++;
    }
}

void display(struct queue *q){
    for(int i=q->f+1;i<q->r+1;i++){
        cout<<q->arr[i]<<endl;
    }
}


int main(){
    struct queue q;
    q.size=10;
    q.f=-1;   
    q.r=-1;   

    q.arr=(int *)malloc(q.size*sizeof(int));
    
    enqueue(&q,13);
    enqueue(&q,25);
    enqueue(&q,12);
    
    dequeue(&q);
    display(&q);
    
    return 0;
}