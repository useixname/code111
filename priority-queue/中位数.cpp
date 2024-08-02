#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];

priority_queue<int,vector<int>,less<int> >q1;//大根堆
priority_queue<int,vector<int>,greater<int> >q2;//小根堆

int main(){
    cin>>n;
    int mid;
    cin>>a[1];
    mid=a[1];
    cout<<mid<<'\n';
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]>mid){
            q2.push(a[i]);
        }
        else{
            q1.push(a[i]);
        }
        if(i&1){
            while(q1.size()!=q2.size()){
                if(q1.size()>q2.size()){
                    q2.push(mid);
                    mid=q1.top();
                    q1.pop();
                }
                if(q1.size()<q2.size()){
                    q1.push(mid);
                    mid=q2.top();
                    q2.pop();
                }
            }
            cout<<mid<<'\n';
        }
    }
    return 0;
}