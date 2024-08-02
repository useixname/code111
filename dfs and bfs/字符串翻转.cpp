#include<bits/stdc++.h>
using namespace std;


void dfs(){
    char ch;
    cin>>ch;
    if(ch!='\n'){
        dfs();
        cout<<ch;
    }
}

int main(){
    dfs();
    return 0;
}