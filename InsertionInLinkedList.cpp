#include<iostream>
using namespace std;

struct Node{
struct Node *next;
int data;
};

struct Node *head=(struct Node*)(malloc(sizeof(struct Node)));

void insert(int element){
struct Node *new_node=(struct Node*)(malloc(sizeof(struct Node)));
new_node->next=head;
new_node->data=element;
head=new_node;
}

void insertInBetween(int element,int index){
struct Node *new_node=(struct Node*)(malloc(sizeof(struct Node)));

struct Node *p=head;
int i=0;

while(i!=index-1){
    p=p->next;
    i++;
}
new_node->data=element;
new_node->next=p->next;
p->next=new_node;

}

void insertAtEnd(int element){
struct Node *new_node=(struct Node*)(malloc(sizeof(struct Node)));
struct Node *ptr=head;

while(ptr->next!=NULL){
    ptr=ptr->next;
}

new_node->next=NULL;
ptr->next=new_node;
new_node->data=element;

}


void display(){ 
    struct Node *ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}

int main(){
    
    struct Node *first=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node *second=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node *third=(struct Node*)(malloc(sizeof(struct Node)));

    head->data=1;
    head->next=first;

    first->data=17;
    first->next=second;

    second->data=27;
    second->next=third;
    
    third->data=47;
    third->next=NULL;
    
    insertAtEnd(32);
    insertInBetween(35,3);
    display();

    return 0;
}