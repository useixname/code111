// 树状数组 区修+点查 O(nlogn)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=500005;
int n,m;
int a[N],s[N]; //s:差分的区间和

int lowbit(int x){ //提取x的低位2次幂数
  return x&-x;
}
void add(int x,int v){ //点修
  while(x<=n) s[x]+=v, x+=lowbit(x);
}
int sum(int x){ //前缀和
  int t=0;
  while(x) t+=s[x], x-=lowbit(x);
  return t;
}
int main(){
  cin>>n>>m; int op,x,y,k;
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&op,&x);
    if(op==1){
      scanf("%d%d",&y,&k);
      add(x,k); add(y+1,-k); //差分
    }
    else printf("%d\n",a[x]+sum(x));
  }
}