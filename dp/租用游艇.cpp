#include <bits/stdc++.h>
using namespace std;
int f[201],n,i,j,x; //f[x]��ʾ��1��x�ľ���
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
        {
            scanf("%d",&x); //a[i][j]
            if (f[j]==0||f[j]>f[i]+x) //���j��û�е������ߵ�j�ľ����ԭ����
                f[j]=f[i]+x; //�滻
        }
    printf("%d\n",f[n]); //�����n�ľ���
}