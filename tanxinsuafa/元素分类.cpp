#include<bits/stdc++.h>
using namespace std;

int a[105];
int n;
int sum1,sum2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<0){
            sum1+=a[i];
        }
        else{
            sum2+=a[i];
        }
    }
    cout<<sum2-sum1;
}