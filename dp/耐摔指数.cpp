#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <map>
#include <set>
#define ll long long 
#define ld long double
#define sl unsigned long long
using namespace std;
typedef pair<ld,ld> PII;
const int inf=0x3f3f3f3f;
const ll mm=0x7fffffffffffffffL;
const int mod=1000000007;
int n,dp[4][10005];//dp[i][j]��ʾ¥��Ϊjʱi���ֻ��Ĳ��Դ��� 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int j=1;j<=n;j++){
        dp[1][j]=j;//��ʼ������һ���ֻ������Դ���Ϊ¥���� 
    }
    for(int i=2;i<=3;i++){//����2��3���ֻ�ʱ�Ĳ��Դ��� 
        for(int j=1;j<=n;j++){//����ÿһ���߶�Ϊj��¥����Ӧ���ֻ�����¼�������
            dp[i][j]=j;//��ʼ�������·�ȡmin 
            for(int k=1;k<j;k++){//���ڸ�j�ߵ�¥���1~j-1�ϲ����ֻ�Ѱ�����Ų���
                dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);//min��ʾ���Ų��� max��ʾ�������
            }
        }
    }
    cout<<dp[3][n];
/*����������� ��ֻ����һ���ֻ�ֻ�ܴӵ�1�����ϵ���߲� ��Ϊ����������۴��м���һ�����ֻ�
һ������ʹ��ˤָ���ò��� ����ֻ�ܴӵ�1�����ϲ��� ������Ϊ������� ����һ��������߲�ų�
��� ����dp[1][j]=j�������ʹ����ÿ�������Ե�������(�����������Դ������) �������Ų��Ա�
ʾ���� ���õ������ٲ��Դ�����˵��m���ֻ��������(m>1)���ǿ���ѡ��ÿһ��¥����в��� ����ȡ
��С�Ĳ��Խ��Ϊ���ô� ��ô����ĳһ��¥k���ǻ���������� һ����ˤ�� һ����ûˤ�� ��ˤ��
����ֻʣһ���ֻ���ô�������dp[m-1][k-1]=k-1(m-1=1)��ˤ���˻�ʣ��ֹһ�� ��ô���Ϊdp[m-1][k-1]
(m-1!=1)��dp���Դ���һ�α�������õ� ��ûˤ�� ����Ϊdp[m][k-j](k-j��ʾ��ʣk-j��¥���Բ���)
Ҳ�ǴӶ���õ�ֵ ���������������ÿһ��¥���õ������ֲ�ͬ���(ˤ����ûˤ��)�϶���ȡ������Ϊ
���������Բ���õ���С�Ĳ��Դ��� Ȼ���ٶ�ÿһ��¥���ԵĽ��ȡminÿȡһ�ξ͸���dp[m][j] ����
״̬ת�Ʒ���Ϊdp[m][j]=min(dp[m][j],max(dp[m-1][k-1],dp[m][j-k])+1)��1��ʾ����ԭ����¥���
���Դ��� ���������ǵ�һ�θ���dp[i][j]ʱҪ��ʼ��һ�����ֵj�Ա���ȡmin����dp[i][j]*/    
    return 0;              
}