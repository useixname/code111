#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int ans[N]={0};

struct node{
  int cnt;
  int k;
}a[N];

int an = -1; // ��Ҫ������˵�ˢ��Ŀ�꣬-1��ʾδ֪

int bs(int n,int &ans){
    int j = 0; // ��¼�ҵ���λ��
    for (int i = 1; i <= n && ans == -1;) {
        j = i++;
        // �ƶ�iָ�룬������j��ͬ��������
        while (i <= n && a[i].cnt == a[i - 1].cnt) i++; 
        // �Ƚ���������
        int l = j - 1, r = n - i + 1; 
        if (l < r) continue;
        else if (l > r) ans = a[j].cnt;
        else ans = a[j].cnt + 1; // ���ڵ�����£�����һ���������������
    }
    return j;
}
bool cmp(node &x,node &y){
    if(x.cnt!=y.cnt){
        return x.cnt<y.cnt;
    }
    return x.k<y.k;
}
/*
5
12 10 15 20 6
6 10 12 15 20
*/

int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i].cnt;
    a[i].k=i;
  }
  sort(a+1,a+1+n,cmp);
  int index=bs(n,an);
  for(int i=1;i<=n;i++){
    if(a[i].cnt<a[index].cnt){
        ans[a[i].k]=an-a[i].cnt;
    }
    else{
        ans[a[i].k]=0;
    }
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}