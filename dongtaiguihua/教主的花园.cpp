#include<bits/stdc++.h>
using namespace std;
int dp[100010][3][2],n,a[100010][3],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);//����ÿ��λ�ø��ָ߶ȵĹ��ͼ�ֵ
    for(int j=0;j<3;j++){//������ĸ߶ȣ������֣�
        for(int i=0;i<3;i++)
            for(int k=0;k<2;k++)dp[1][i][k]=0;//��ʼ����ȫ����ֵΪ0
        dp[1][j][0]=dp[1][j][1]=a[1][j];//��ʼֵΪa[1][j]
        for(int i=2;i<=n;i++){//ѭ��ÿ��λ��������
            dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][2][1])+a[i][0];
            dp[i][1][0]=dp[i-1][2][1]+a[i][1];
            dp[i][1][1]=dp[i-1][0][0]+a[i][1];
            dp[i][2][1]=max(dp[i-1][1][0],dp[i-1][0][0])+a[i][2];
        }
        for(int i=0;i<j;i++)ans=max(ans,dp[n][i][0]);//�������ans��<=j�ĸ߶ȿ϶��Ǳ������ģ�����Ϊdp[n][i][0]
        for(int i=2;i>j;i--)ans=max(ans,dp[n][i][1]);//���������ƣ�>j�Ŀ϶��Ǳ����ߵģ�����Ϊdp[n][i][1]
    }
    printf("%d",ans);//������
    return 0;
}