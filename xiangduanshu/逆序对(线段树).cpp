//Ȩֵ�߶���+��ɢ�� nlogn
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define ls u<<1
#define rs u<<1|1
#define mid ((l+r)>>1)
#define LL long long
const int N=500005;
int n,m,a[N],b[N];
int sum[N<<2]; //�������ĳ��ִ���֮��

void pushup(int u){ //�ϴ�
  sum[u]=sum[ls]+sum[rs];
}
void change(int u,int l,int r,int x){ //����
  if(l==r){sum[u]++; return;}
  if(x<=mid) change(ls,l,mid,x);
  else change(rs,mid+1,r,x);
  pushup(u);
}
LL query(int u,int l,int r,int x,int y){ //����
  if(x<=l && r<=y) return sum[u];
  LL s=0;
  if(x<=mid) s+=query(ls,l,mid,x,y);
  if(y>mid) s+=query(rs,mid+1,r,x,y);
  return s;
}
int main(){
  scanf("%d",&n);
  for(int i=1; i<=n; i++) 
    scanf("%d",&a[i]),b[i]=a[i];
  sort(b+1,b+n+1);
  LL s=0;
  for(int i=1; i<=n; i++){
    int id=lower_bound(b+1,b+n+1,a[i])-b;
    change(1,1,n,id);
    s+=query(1,1,n,id+1,n);
    // id����������Ȳ����Ҵ���id����
  }
  printf("%lld\n",s);
}