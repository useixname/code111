#include<bits/stdc++.h>
using namespace std;
#define int long long
int now=0;
char op;
stack<int> a;

signed main(){
    ios_base::sync_with_stdio(0);
    while((op=getchar())!='@'){
        if(op>='0'&&op<='9'){
            now*=10;now+=op-'0';
        }
        else if(op=='.'){
            a.push(now);
            now=0;
        }
        else if(op=='+'){
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(x+y);
        }
        else if(op=='-'){
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(y-x);
        }
        else if(op=='*'){
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(x*y);
        }
        else if(op=='/'){
            int x=a.top();
            a.pop();
            int y=a.top();
            a.pop();
            a.push(y/x);
        }
    }
    cout<<a.top();
    return 0;
}