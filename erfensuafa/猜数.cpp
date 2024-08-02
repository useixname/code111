#include <cstdio>                         // �ڱ����в����Ǳ����

extern "C" int Seniorious(int);           // ��������Ҫ����һ�ν���������ĺ�����

extern "C" int Chtholly(int n, int OvO) { // ������ʵ�ֽ�����Ҫ����ʵ�ֵĺ�����
  int ans;
  int l=1,r=n;
  while(l<=r){
    int mid=(l+r)>>1;
    int x=Seniorious(mid);
    if(x==1){
        r=mid-1;
    }
    else if(x==-1){
        l=mid+1;
    }
    else{
        ans=mid;
        break;
    }
  }
  return ans;
}