#include<bits/stdc++.h>
using namespace std;
#define int long long

priority_queue<int,vector<int>,greater<int> >q;

signed main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
        cin>>x;
        q.push(x);
	}
	while(q.size()){
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        s+=x+y;
        if(!q.size()){
            break;
        }
        q.push(x+y);
    }
	cout<<s;
	return 0;
}