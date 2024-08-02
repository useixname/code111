#include<bits/stdc++.h>
using namespace std;

const int N=1e8+10;
string a[N];
int n;

bool cmp(string s1,string s2){
    return s1+s2<s2+s1;
}

bool cmp1(string s1,string s2){
    return s1+s2>s2+s1;
}

int main(){
    string s;
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        a[i]=s[i];
    }
    sort(a,a+n,cmp1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<" ";
    sort(a,a+n,cmp);
    if(a[0]=="0"){
      swap(a[0],a[1]);
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}