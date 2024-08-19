#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=105;
vector<PII>a;
int b[N],vis[N],next1[N],ret[N];
int n,ans=0;

typedef struct LNode{
    PII data;
    LNode *next,*pre;
}LNode,*Linklist;

Linklist L;
void insert(Linklist L,int n){
    Linklist s;
    Linklist r=L->next;
    for(int i=1;i<=n-1;i++){
        r=r->next;
    }
    s->data.first=r->data.first;
    s->data.second=r->next->data.second;
    r->next=s;
    s->next=r->next->next;
}
void create(Linklist &L,int n){
    Linklist s,r;
    L=(Linklist)malloc(sizeof(LNode));
    L->data.first=b[1];
    L->data.second=b[2];
    L->next=NULL;
    r=L;
    for(int i=2;i<=n;i++){
        s=(Linklist)malloc(sizeof(LNode));
        s->data.first=b[i];
        s->data.second=b[i+1];
        L->next=s;
        L=L->next;
    }
    L->next=r;
}

void dfs(int step,int sum){
    if(step==n){
        //cout<<sum<<'\n';
        ans=max(ans,sum);
        // for(int i=1;i<=n-1;i++){
        //     cout<<ret[i]<<" ";
        // }
        // cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int m=next1[i];
            ret[step]=i;
            if(i!=n){
                vis[m]=1;
                int y=a[i].first;
                int t=a[i].second;
                int z=a[m].second;
                a[i].second=a[m].second;
                next1[i]=next1[m];
                dfs(step+1,sum+y*t*z);
                vis[m]=0;
                a[i].second=a[m].first;
                next1[i]=m;
            }
            else{
                vis[1]=1; 
                int y=a[i].first;
                int t=a[i].second;
                int z=a[m].second;
                a[i].second=a[m].second;
                next1[i]=next1[m];
                dfs(step+1,sum+y*t*z);
                vis[m]=0;
                a[i].second=a[m].first;
                next1[i]=m;
            }
        }
    }
}

void print_link(Linklist L,int n){
    Linklist r=L->next;
    while(n--){
        cout<<r->data.first<<" "<<r->data.second<<'\n';
        r=r->next;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        next1[i]=i+1;
    }
    next1[n]=1;
    b[n+1]=b[1];
    create(L,n);
    a.push_back({0,0});
    for(int i=1;i<=n;i++){
        a.push_back({b[i],b[i+1]});    
        //cout<<a[i].first<<" "<<a[i].second<<'\n';
    }
    //print_link(L,n);
    dfs(1,0);
    cout<<ans;
    return 0;
}