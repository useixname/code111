#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n;
int a[100100];
int mid;
priority_queue<int,vector<int>,less<int> >q1;//大根堆
priority_queue<int,vector<int>,greater<int> >q2;//小根堆
int main(){
    cin>>n;
    scanf("%d",&a[1]);
    mid=a[1];
    cout<<mid<<endl;//mid初值是a[1]
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>mid) q2.push(a[i]);
        else q1.push(a[i]);
        if(i%2==1){//第奇数次加入
            while(q1.size()!=q2.size()){
                if(q1.size()>q2.size()){
                    q2.push(mid);
                    mid=q1.top();
                    q1.pop();
                }
                else{
                    q1.push(mid);
                    mid=q2.top();
                    q2.pop();
                }
            }
            cout<<mid<<endl;
        }
    }
    return 0;
}