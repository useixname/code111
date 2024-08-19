// ��״���� ����+���� O(nlogn)
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,s[500005]; //�����

int lowbit(int x){ //��ȡx�ĵ�λ2������
  return x&-x;
}
void add(int x,int k){ //����
  while(x<=n) s[x]+=k, x+=lowbit(x);
}
int sum(int x){ //ǰ׺��
  int t=0;
  while(x) t+=s[x], x-=lowbit(x);
  return t;
}
signed main(){
  cin>>n>>m;
  memset(s, 0, sizeof(s));
  char op;int x,y;
  for(int i=1;i<=m;i++){
    cin>>op>>x>>y;
    if(op=='x') add(x,y);
    else {
        int result = sum(y) - sum(x - 1);
        printf("%lld\n",result);
        }
  }
  return 0;
}