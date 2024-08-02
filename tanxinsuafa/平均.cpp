#include<bits/stdc++.h>
using namespace std;

vector<int> a[10];
int n,ans=0;

int main(){
    cin>>n;
    int cnt=n/10;
    for(int i=0;i<n;i++){
        int num,count;
        cin>>num>>count;
        a[num].push_back(count);
    }
    for(int i=0;i<=9;i++){
        if(a[i].size()>cnt){
            sort(a[i].begin(),a[i].end(),greater<int>());
            for(int j=cnt;j<a[i].size();j++){
                ans+=a[i][j];
            }
        }
    }
    cout<<ans;
}
