#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;
  

 
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));

    if(n==NULL){
        cout<<"Overflow"<<endl;
    }
    else{
    n->data=val;
    n->next=NULL;
    if(f==NULL){
        f=r=n;
    }
    else{
      r->next=n;
      r=n;
      
    }

    }
}
 



void dequeue()
{
    struct Node *ptr = f;
    if(f==NULL){
        cout<<"Underflow"<<endl;
    }
    else{
        f = f->next;
        free(ptr);
    }
}

void peek(){
    cout<<"peek element is: "<<endl;
    cout<<f->data<<endl;
}


void display(struct Node *ptr)
{
    cout<<"Elements in the queue are:"<<endl;
    while (ptr != NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}


int main()
{
    int option=0;

    while(option!=5){
    cout<<"Which operation you want to perform"<<endl;
    cout<<"1. Enqueue 2. Dequeue 3. Peek 4. Display 5. Quit"<<endl;

    cin>>option;

    if(option==1){
        int element;
        cout<<"Enter the data you want to enqueue"<<endl;
        cin>>element;
        enqueue(element);
    }
    else if(option==2){
        dequeue();
    }
    else if(option==3){
        peek();
    }
    else if(option==4){
        display(f);
    }
    else{
        return 0;
    }

    }
    return 0;
}
