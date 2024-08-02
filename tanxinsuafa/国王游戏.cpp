#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
  int a,b;
  bool operator<(node &t){
    return a*b<t.a*t.b;
  }
}p[1005]; //p[]存储每人的手中数
int m[4005],a[4005],t[4005];
int lm,la,lt;
//m[]存储乘积,a[]存储答案,t[]辅助存储

void mul(int m[],int b,int t[]){ //m*b=t
  for(int i=1;i<=lt;i++) t[i]=0;
  for(int i=1;i<=lm;i++) t[i]+=m[i]*b;
  lm+=4; //因为b<10000
  for(int i=1;i<lm;i++){
    t[i+1]+=t[i]/10;  //存进位
    t[i]%=10;         //存余数
  }
  while(t[lm]==0&&lm>1) lm--; //去0
  for(int i=1;i<=lm;i++) m[i]=t[i];
}
void div(int m[],int b,int t[]){ //m/b=t
  for(int i=1;i<=lt;i++) t[i]=0;
  int r=0;
  for(int i=lm;i>=1;i--){
    r=r*10+m[i];  //被除数
    t[i]=r/b;     //存商
    r%=b;         //余数
  }
  lt=lm;
  while(t[lt]==0&&lt>1) lt--; //去0
}
bool cmp(int a[],int t[]){
  if(la!=lt) return la<lt; 
  for(int i=lt; i; i--)
    if(a[i]!=t[i]) return a[i]<t[i];
  return false; //相等时返回false
}
void upd(int a[],int t[]){
  if(cmp(a,t)){ //若a<t,更新答案
    for(int i=lt;i;i--) a[i]=t[i];
    la=lt;
  }
}
int main(){
  int n; scanf("%d",&n);
  for(int i=0;i<=n;i++)
    scanf("%d%d",&p[i].a,&p[i].b);
  sort(p+1,p+n+1);
  
  m[++lm]=p[0].a;
  for(int i=1; i<=n; i++){
    div(m,p[i].b,t);
    upd(a,t);
    mul(m,p[i].a,t);
  }
  for(int i=la;i;i--) cout<<a[i];
  return 0;
}