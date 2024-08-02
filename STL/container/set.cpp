#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct node{
    int x,y;
    bool operator< (const node W)const
	{
		return x>W.x;  //°´xµÄÖµÉýÐò 
	}
}a[N];

int main(){
    int n;
    cin>>n;
    set<node> s;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        s.insert(a[i]);
    }
    for(auto i=s.begin();i!=s.end();i++){
        auto t=*i;
        cout<<t.x<<" "<<t.y<<'\n';
    }
    return 0;
}
