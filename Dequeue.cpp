#include<iostream>
using namespace std;

struct dequeue{
    int size;
    int f;
    int r;
    int *arr;
};


int isFull(struct dequeue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct dequeue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}


void enqueueR(struct dequeue *q,int element){
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=element;
    }
}

void enqueueF(struct dequeue *q,int element){
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q->f--;
        q->arr[q->f+1]=element;
    }
}

void dequeueF(struct dequeue *q){
    if(isEmpty(q)){
        cout<<"Queue Underflwow"<<endl;
    }
    else{
        q->f++;
    }
}


void dequeueR(struct dequeue *q){
    if(isEmpty(q)){
        cout<<"Queue Underflwow"<<endl;
    }
    else{
        q->r--;
    }
}



void display(struct dequeue *q){
    for(int i=q->f+1;i<q->r+1;i++){
        cout<<q->arr[i]<<endl;
    }
}



int main(){
    struct dequeue q;
    q.size=10;
    q.f=-1;   
    q.r=-1;   

    q.arr=(int *)malloc(q.size*sizeof(int));
    
    cout<<"Inserting at rear:"<<endl;
    enqueueR(&q,12);
    enqueueR(&q,15);
    enqueueR(&q,23);
    display(&q);
    
    cout<<"Inserting at front:"<<endl;
    enqueueF(&q,33);
    enqueueF(&q,20);
    display(&q);
    
    cout<<"Deleting from front:"<<endl;
    dequeueF(&q);
    display(&q);
    
    cout<<"Deleting from front:"<<endl;
    dequeueR(&q);
    display(&q);
    return 0;
}