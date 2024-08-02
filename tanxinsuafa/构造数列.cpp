#include<bits/stdc++.h>
using namespace std;

int t,n;

void find_shulie(int n){
    int ret[10];
    int ans=0;
    while(n!=0){
        string s=to_string(n);
        int len=s.size();
        int num=(s[0]-'0')*pow(10,(len-1));
        ret[ans]=num;
        n-=num;
        ans++;
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<ret[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        find_shulie(n);
    }
}