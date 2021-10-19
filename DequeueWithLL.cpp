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
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueueR(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 


void enqueueF(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next=f;
        f=n;
    }
}
 

void dequeueF()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
}

 
void dequeueR()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        while(ptr->next!=r){
            ptr=ptr->next;
        }

        r=ptr;
        r->next=NULL;
        val = ptr->data;
        free(ptr);
    }
}

int main()
{
    enqueueR(34);
    enqueueR(4);
    enqueueR(7);
    enqueueR(17);
    enqueueF(127);
    enqueueF(33);
    enqueueF(20);

    dequeueF();
    display(f);
    return 0;
}
