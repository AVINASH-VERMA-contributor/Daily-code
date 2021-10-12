#include<iostream>
using namespace std;

struct Node{
struct Node *next;
int data;
};

struct Node *head=(struct Node*)(malloc(sizeof(struct Node)));

void deletefirst(){
struct Node *ptr=head;
head=head->next;
free(ptr);
}

void deleteInBetween(int index){
    struct Node *p=head;
    struct Node *q=head->next;

    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);    
}

void deletelast(){
struct Node * ptr=head;
while(ptr->next->next!=NULL){
    ptr=ptr->next;
}
ptr->next=NULL;
}

int deleteNodeWithValue(int value){
struct Node * ptr=head;
if(head->data==value){
    head=head->next;
    return 0;
}

while(ptr->next->data!=value){
    ptr=ptr->next;
}
ptr->next=ptr->next->next;

return 0;
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

   deletefirst();
    deleteInBetween(2);
   deleteNodeWithValue(17);
   deletelast();
    
    display();

    return 0;

}