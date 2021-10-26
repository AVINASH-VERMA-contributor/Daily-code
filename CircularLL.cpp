#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=(struct Node*)(malloc(sizeof(struct Node)));

void display(struct Node *head){
    struct Node *ptr=head;
    cout<<"Elements of the circular Linked list are:"<<endl;
    do{
        cout<<ptr->data<<endl;
        ptr=ptr->next;

    }while(ptr!=head);
}

void insertAtEnd(int val,struct Node *head){
    struct Node *new_node=(struct Node*)(malloc(sizeof(struct Node)));
    new_node->next=head;
    new_node->data=val;

    struct Node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    head=new_node;
    ptr->next=head;
}


struct Node* insertAtfront(int val,struct Node *head){
    struct Node *new_node=(struct Node*)(malloc(sizeof(struct Node)));
    new_node->data=val;

    struct Node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=new_node;
    new_node->next=head;
    head=new_node;
    return head;
}


int main(){
    struct Node *first=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node *second=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node *third=(struct Node*)(malloc(sizeof(struct Node)));

    head=first;    

    first->data=12;
    first->next=second;
    
    second->data=33;
    second->next=third;
    
    third->data=40;
    third->next=first;

    display(&*head);
    insertAtEnd(45,&*head);
    insertAtEnd(85,&*head);
    insertAtEnd(67,&*head);
    display(&*head);

    head=insertAtfront(256,&*head);
    head=insertAtfront(17,&*head);
    display(&*head);


}