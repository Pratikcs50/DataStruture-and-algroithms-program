#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
};
node* getnode(int data){
    node* newnode= new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int data){
    if(root==NULL){
        root=getnode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

//fucntion to print lowest common ancestor
node* lca(node* root,int v1,int v2){
    if(v1<root->data&&v2<root->data){
        return lca(root->left,v1,v2);
    }
   else if(v1>root->data&&v2>root->data){
        return lca(root->right,v1,v2);
   }
   else{
       return root;
   }
    
    return nullptr;
}

int main(){
    node* root=NULL;
    int nodes;
   // cout<<"enter number of nodes to enter : "<<endl;
    cin>>nodes;
    while(nodes--){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    int v1,v2;
    cin>>v1>>v2;
    node* ans=lca(root,v1,v2);
    cout<<ans->data<<endl;
}