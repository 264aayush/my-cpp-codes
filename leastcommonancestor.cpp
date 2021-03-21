#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(){
        left=NULL;
        right=NULL;
    }
    node(int x){
        data=x;
        left=NULL;
        right=NULL;    
    }
};

node* insert(node* root,int data){
    if(root==NULL)
        return new node(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else 
        root->right=insert(root->right,data);
    return root;
}

node * find(node* root,int x){
    if(root==NULL)
        return NULL;
    if(x<root->data)
        return find(root->left,x);
    if(x>root->data)
        return find(root->right,x);
    return root;
}

int lcautil(node* root,int a,int b){
    if(root==NULL)
        return -1;
    if(a<root->data && b<root->data)
        return lcautil(root->left,a,b);    
    if(a>=root->data && b>=root->data)
        return lcautil(root->right,a,b);    
    return root->data;
}

int lca(node* root,int a,int b){
    if(find(root,a)==NULL||find(root,b)==NULL)
        return -1;
    return lcautil(root,a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    node* root=NULL;
    loop(i,0,n){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    cout<<lca(root,500,25)<<endl;
    cout<<lca(root,81,60)<<endl;

	return 0;
}