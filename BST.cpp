#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* create(int value){
    Node* newNode= new Node;
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insertion(Node* root,int value){
    if(root==NULL){
        return create(value);
    }

    if(value<root->data){
       root->left=insertion(root->left,value);
    }
    else{
        root->right=insertion(root->right,value);
    }

return root;
}

int search(Node* root,int value){

    if(root==NULL){
        return -1;
    }
    
    if(root->data==value){
        return 1;
    }
    
    if(value<root->data){
        search(root->left,value);
    }
    else if(value>root->data){
        search(root->right,value);
    }

}

Node* deletion(Node* root,int value){
    if(root==NULL){
        return root;
    }

    if(value<root->data){
        root->left=deletion(root->left,value);
    }
    else if(value > root->data){
        root->right=deletion(root->right,value);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            return NULL;   
        }
    }

return root;
}

void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
    
    inorder(root->left);  
    cout<< root->data << "   ";  
    inorder(root->right); 
}  


void preorder(Node *root)  
{  
    if (root == NULL)  
        return;  

    cout<< root->data << "   ";  
    preorder(root->left);  
    preorder(root->right);  
}  

void postorder(Node *root)  
{  
    if (root == NULL)  
        return;  
    
    postorder(root->left);  
    postorder(root->right);  
    cout<< root->data << "   ";  
}  

int main(){
    Node* root=NULL;
    int option=0;

while(option!=7){
    cout<<"Choose what you want to do: 1. Insert 2. Search 3. Preorder 4.Inorder 5.Postorder 6.Delete 7.Quit"<<endl;
    cin>>option;

    if(option==1){
        cout<<"Enter the value you want to insert:"<<endl;
        int value;
        cin>>value;
        root=insertion(root,value);
    }
    else if(option==2){
        cout<<"Enter the value you want to search: ";
        int element;
        cin>>element;
        int found=search(root,element);

        if(found==1){
            cout<<"Found"<<endl;
        }else cout<<"Not found"<<endl;
    }
    else if(option==3){
        cout<<"preorder: ";
        preorder(root);
        cout<<endl; 

    }
    else if(option==4){
        cout<<"Inorder: ";
        inorder(root);
        cout<<endl; 

    }
    else if(option==5){
        cout<<"Postorder: ";
        postorder(root);
        cout<<endl; 
    }
    else if(option==6){
        int element;
        cout<<"Enter the value of node you want to delete: ";
        cin>>element;
        root=deletion(root,element);
    }
    else{
        return 0;
    }
}
    return 0;
}