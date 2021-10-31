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


void enqueueRear(struct dequeue *q,int element){
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=element;
    }
}

void enqueueFront(struct dequeue *q,int element){
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q->f--;
        q->arr[q->f+1]=element;
    }
}

void dequeueFront(struct dequeue *q){
    if(isEmpty(q)){
        cout<<"Queue Underflwow"<<endl;
    }
    else{
        q->f++;
    }
}


void dequeueRear(struct dequeue *q){
    if(isEmpty(q)){
        cout<<"Queue Underflwow"<<endl;
    }
    else{
        q->r--;
    }
}



void display(struct dequeue *q){
    cout<<"Elements in queue are:"<<endl;
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

    int option=0;    
    while(option!=6){
   cout<<"Choose what you want to do:"<<endl;
   cout<<"1.EnqueueRear 2.EnqueueFront 3.DequeueFront 4.DequeueRear 5.Display 6.Quit"<<endl;
    cin>>option;

    if(option==1){
        int element;
        cout<<"Enter the value you want to enqueue"<<endl;
        cin>>element;
        enqueueRear(&q,element);
    }
    
    else if(option==2){
        int element;
        cout<<"Enter the value you want to enqueue"<<endl;
        cin>>element;
        enqueueFront(&q,element);
    }

    else if(option==3){
        dequeueFront(&q);
    }
    
    else if(option==4){
        dequeueRear(&q);
    }

    else if(option==5){
        display(&q);
    }
    else{
        return 0;
    }

    }
    return 0;
}