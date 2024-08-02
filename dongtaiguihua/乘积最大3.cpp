#include<bits/stdc++.h>
using namespace std;
#define MAXN 110
 
struct bign
{
	int len,s[MAXN];
	bign()
	{
		memset(s,0,sizeof(s));
		len=1;
	}
	bign operator + (const int b) 
	{
		s[1]+=b;
		for (int i=1;s[i]>=10;i++)
		{
			s[i+1]+=s[i]/10;
			s[i]%=10; 
		}
		if (s[len+1]>0) len=len+1;
		return *this;
	}
	bign operator * (const bign& b)
	{
		bign c;  
        c.len = len + b.len;  
        for(int i = 1; i <= len; i++)  
        {  
            for(int j = 1; j <= b.len; j++)  
            {  
                c.s[i+j-1] += s[i] * b.s[j];  
            }  
        }  
        for(int i = 1; i <= c.len; i++)  
        {  
            c.s[i+1] += c.s[i]/10;  
            c.s[i] %= 10;
        }  
        while(c.len > 1 && !c.s[c.len]) c.len--;
        return c;  
	}	
}f[MAXN][MAXN],sum[MAXN][MAXN];
 

int a[MAXN];
int n,m;

void init()
{
	scanf("%d%d",&n,&m);
	bign ten;
	ten=ten+10;
	for (int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			sum[i][j]=sum[i][j-1]*ten+a[j];
	for (int i=1;i<=n;i++)
		f[i][0]=sum[1][i];
}
 
bign max(bign a,bign b)
{
	if (a.len<b.len) return b;
    if (a.len>b.len) return a;
    for (int i=a.len;i>0;i--){
        if (a.s[i]>b.s[i]) return a;
        if (a.s[i]<b.s[i]) return b;
    }
    return a;	
}
 
void print(bign a)
{
	for (int i=a.len;i>0;i--)
		putchar(a.s[i]+48);
}
 
int main()
{
	init();	
	for (int j=1;j<=m;j++)
		for (int i=j+1;i<=n;i++)
			for (int k=j;k<=i-1;k++)
				f[i][j]=max(f[i][j],f[k][j-1]*sum[k+1][i]);
	print(f[n][m]);	
	return 0;
}