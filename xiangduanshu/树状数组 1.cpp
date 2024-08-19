// ��״���� ����+���� O(nlogn)
#include <iostream>
#include <cstring>
#include <algorithm>
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
int main(){
  cin>>n>>m; int op,x,y;
  for(int i=1;i<=n;i++)
    scanf("%d",&y), add(i,y);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&op,&x,&y);
    if(op==1) add(x,y);
    else printf("%d\n",sum(y)-sum(x-1));
  }
}