#include<bits/stdc++.h>
using namespace std;
char op;
stack<char> s;
int main(){
    ios_base::sync_with_stdio(0);
    while((op=getchar())!='@'){
        if(op=='('){
            s.push(op);
        }
        else if(op==')'){
            if(!s.size()){
                cout<<"NO";
                return 0;
            }
            s.pop();
        }
        else{
            continue;
        }
    }
    if(s.size()==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}