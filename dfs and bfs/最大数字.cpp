#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char c[20];
LL ans=0;
//n:1�Ų���ʣ�����  m:2�Ų���ʣ�����
int n,m;
void dfs(int i,LL v){
	int x=c[i]-'0';
	if(c[i]){
		//Ӧ��ʹ�õĲ�������
		int t=min(n,9-x);
		n-=t;
		dfs(i+1,v*10+x+t);
		//����
		n+=t;
        //���ǲ���2�Ƿ��ܹ�ʹ��
		if(m>x){
			m-=x+1;
			dfs(i+1,v*10+9);
            //����
			m+=x+1;
		}
	}else{
        //��ȡmax
		ans=max(ans,v);
	}
}
int main() 
{
	scanf("%s%d%d",c,&n,&m);
	dfs(0,0);
	printf("%lld\n",ans);
    return 0;
}
