#include<iostream>
using namespace std;

const int N = 100010;

int m,n;

int a[N],diff[N];

// void insert(int x1,int y1,int x2,int y2,int c){
//     diff[x1][y1]+=c;
//     diff[x2+1][y2+1]+=c;
//     diff[x1][y2+1]-=c;
//     diff[x2][y1+1]-=c;
// }

void insert(int l,int r,int c){
    diff[l]+=c;
    diff[r+1]-=c;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(i,i,a[i]);
    }
    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++){
        diff[i]+=diff[i-1];
        cout<<diff[i]<<" ";
    }
}