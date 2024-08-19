// ��״���� ����+��� O(nlogn)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 500005
struct node{
  int val,pos; //ֵ,λ��
}a[N];
int n,s[N];
long long ans;

void add(int x,int k){ //����
  while(x<=n) s[x]+=k, x+=x&-x;
}
int sum(int x){ //ǰ׺��
  int t=0;
  while(x) t+=s[x], x-=x&-x;
  return t;
}
int cmp(node x,node y){ //��������
  if(x.val==y.val) return x.pos>y.pos;  
  return x.val>y.val;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) 
    scanf("%d",&a[i].val),a[i].pos=i;
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++){ //��ǰ����>ai�ĸ���
    ans+=sum(a[i].pos-1);
    add(a[i].pos,1);
  }
  printf("%lld\n",ans);
}