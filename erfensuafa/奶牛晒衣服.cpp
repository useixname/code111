#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c[N];
int n,a,b;

bool chk(int mid){
    int t;
    if(c[n]-mid*a<=0){
        return true;
    }
    else{
        int x=c[n]-mid*a;
        t=x/b;
        if(x-t*b>0){
            t++;
        }
        if(t>mid){
            return false;
        }
        else{
            int d=mid-t;
            for(int i=1;i<=n-1;i++){
                int temp=c[i]-mid*a;
                if(temp>0){
                    if(d<=0){
                        return false;
                    }
                    else{
                        int t1=temp/b;
                        if(temp-t1*b>0){
                            t1++;
                        }
                        if(t1>d){
                            return false;
                        }
                        else{
                            d-=t1;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    int l=0,r=c[n]/a+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r;
    return 0;
}