#include<iostream>
#include<string>
using namespace std;
#define Alphabet_Size 26
/*
    Trie: Prefix Tree
    Application : words auto-complete using Trie
*/
struct node{
    bool is_end;
    node *child[Alphabet_Size];
    node(){
        is_end=false;
        for(int i=0;i<Alphabet_Size;i++) child[i]=nullptr;
    };
};

void Insert(node *root,string word){
    node *temp= root;
    for(char ch :word){
        int index= ch-'a';

        if(temp->child[index]==nullptr){
            temp->child[index]=new node;
        }

        temp= temp->child[index];
    }

    temp->is_end= true;
}

bool Search(node *root,string word){
    node *temp= root;

    for(char ch: word){
        int index=ch-'a';

        if(temp->child[index]==nullptr) return false;

        temp= temp->child[index];
    }

    return temp->is_end;
}
int main(){
    int n=8;
    string words[n]={"zerojudge", "zero", "zoo",
                    "zone", "z", "aaaaa",
                     "add", "az" };
    node *root=new node;

    for(int i=0;i<n;i++){
        Insert(root,words[i]);
    }

    cout<<(Search(root,"az")? "Yes\n":"No\n");
    cout<<(Search(root,"azc")? "Yes\n":"No\n");
    cout<<(Search(root,"zero")? "Yes\n":"No\n");

    return 0;
}