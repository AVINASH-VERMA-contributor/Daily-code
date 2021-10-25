#include<iostream>
using namespace std;
 
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void display(struct Node *ptr)
{
    cout<<"Elements in the queue are:"<<endl;
    while (ptr != NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
 
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


int main()
{
    enqueue(34);
    enqueue(14);
    enqueue(24);
    
    peek();
    dequeue();
    display(f);
    peek();

    return 0;
}
