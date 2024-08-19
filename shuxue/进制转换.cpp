#include<bits/stdc++.h>
using namespace std;
#define int long long
string c="0123456789ABCDEF";
string s;
char ans[35];
int n,m,len=0;


int quikly_pow(int n,int m){
    int ret=1;
    while(m){
        if(m&1){
            ret*=n;
        }
        m>>=1;
        n=n*n;
    }
    return ret;
}
void z(){
    int sum=0,k=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]<'A'){
            sum+=quikly_pow(n,k++)*(s[i]-'0');
        }
        else{
            sum+=quikly_pow(n,k++)*(s[i]-'A'+10);
        }
    }
    while(sum){
        ans[len]=c[sum%m];
        sum/=m;
        if(sum==0){
            break;
        }
        len++;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s>>m;
    z();
    for(int i=len;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}