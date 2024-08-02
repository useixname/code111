#include<bits/stdc++.h>
using namespace std;

const int N=3;
char a[N];
void jz(int n,int r){
    int k=N;
    while(n>0){
        char ch;
        int t=n%r;
        // if(t>=10){
        //     ch=(t+55);
        // }
        // else{
        //     ch=t+'0';
        // }
        ch=t+97;
        a[--k]=ch;
        n/=r;
    }
}
int main(){
    memset(a,'a',sizeof(a));
    int t;
    cin>>t;
    while(t--){
        int n;
        int s=0,k=4;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            s+=(x*pow(10,k));
            k--;
            if(i%5==0){
                cout<<s<<'\n';
                jz(s,26);
                for(int i=0;i<N;i++){
                    cout<<a[i];
                }
                s=0;
                k=4;
            }
        }
        cout<<'\n';
    }
    return 0;
}