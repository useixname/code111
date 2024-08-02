#include<bits/stdc++.h>
using namespace std;

typedef  int Element;

typedef struct LNode{
    Element data;
    LNode *next,*pre;
}LNode,*Linklist;

//带头节点的头插法;

void create(Linklist &L,int n){
    Linklist r,s;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;
    for(int i=1;i<=n;i++){
        s=(Linklist)malloc(sizeof(LNode));
        s->data=i;
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
    L->pre=r;
}

void insert(Linklist &L,int k,char ch){
    if(ch=='L'){
        Linklist r,s;
        r=L;
        s=(Linklist)malloc(sizeof(LNode));
        s->data=k;
        s->next=r->next;
        r->next=s;
    }
    if(ch=='R'){
        Linklist r,s;
        r=L->pre;
        s=(Linklist)malloc(sizeof(LNode));
        s->data=k;
        r->next=s;
        s->next=NULL;
    }
}
void print_link(Linklist L){
    Linklist r=L->next;
    while(r){
        cout<<r->data<<" ";
        r=r->next;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    Linklist L;
    create(L,n);
    for(int i=1;i<=m;i++){
        char ch;
        int k;
        cin>>ch>>k;
        insert(L,k,ch);
    }
    print_link(L);
}