#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;


struct node
{
    int x;
    node* next;
    node(){
        x=1;
        next=NULL;
    }
    node(int a){
        x=a;
        next=NULL;
    }
};

node * fun(node* head){
    if(head==NULL||(head->next)==NULL)
        return head;
    node* p=head;
    node * q=p->next;
    int i=3;
    while((p!=NULL && q!=NULL) && i--){
        node * temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    head->next=fun(q);
    return p;
}


int main() {
    node * head=new node();
    node* temp=head;
    for(int i=2;i<=6;i++){
        temp->next=new node(i);
        temp=temp->next;
    }

    temp=fun(head);
    
    while(temp!=NULL){
        cout<<(temp->x)<<" ";
        temp=temp->next;
    }
	return 0;
}
