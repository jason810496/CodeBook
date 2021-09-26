#include<iostream>
using namespace std;

struct node{
    node *Left=nullptr,*Right=nullptr;
    int data;
    node(int Data){
        data=Data;
    }
};

void Add_node(int Data,node *&Ptr){
    if(Ptr==nullptr){
        Ptr=new node(Data);
        return;
    }
    if(Data > Ptr->data) Add_node(Data,Ptr->Right);
    else Add_node(Data,Ptr->Left);
}
void Preorder(node *root){
    if(root==nullptr) return;

    cout<<root->data<<' ';
    Preorder(root->Left);
    Preorder(root->Right);
}
void Inorder(node *root){
    if(root==nullptr) return;

    Inorder(root->Left);
    cout<<root->data<<' ';
    Inorder(root->Right);

}
void Postorder(node *root){
    if(root==nullptr) return;

    Postorder(root->Left);
    Postorder(root->Right);
    cout<<root->data<<' ';
}
int main(){
    node *root=nullptr;
    for(int i=1;i<=5;i++) Add_node(i,root);
    Preorder(root);
    return 0;
}