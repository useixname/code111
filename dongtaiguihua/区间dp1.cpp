#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105];
int dpmin[205][205];//��С
int dpmax[205][205];//���
int sum[205];
int main()
{
    int n;
    scanf("%d",&n);
    memset(sum,0,sizeof(sum));
    memset(dpmin,INF,sizeof(dpmin));
    memset(dpmax,-1,sizeof(dpmax));
    for(int  i =1;i<=n;i++){
        scanf("%d",&stone[i]);
        sum[i] = sum[i - 1] + stone[i];
        dpmin[i][i] = 0;
        dpmax[i][i] = 0;
    }
    for(int i = 1;i<=n-1;i++){
        sum[i+n] = sum[i+n-1]+stone[i];//չ����n�����n-1~1����
        dpmin[i+n][i+n] = 0;
        dpmax[i+n][i+n] = 0;
    }
    for(int len = 1;len<=n;len++){//���Ȼ������n
        for(int j = 1;j+len<=2*n;j++){//���ö�����2*n-1,ends<=2*n-1
            int ends = j+len - 1;
            for(int i = j;i<ends;i++){//ע�⣡i<ends��������Ϊi=endsʱ��dp[ends+1][ends]�ǲ������ģ�
                dpmin[j][ends] = min(dpmin[j][ends],dpmin[j][i]+dpmin[i+1][ends]+sum[ends]-sum[j-1]);
                dpmax[j][ends] = max(dpmax[j][ends],dpmax[j][i]+dpmax[i+1][ends]+sum[ends]-sum[j-1]);
            }
        }
    }
    int ansmin = 0xfffffff;
    int ansmax = -1;
    for(int i = 1;i<=n;i++){
        ansmin = min(ansmin,dpmin[i][i+n-1]);//��1~n,2~n~1,3~n~2....�ĺϲ�n���ѵ���������С��ֵ
        ansmax = max(ansmax,dpmax[i][i+n-1]);
    }
    cout<<ansmin<<endl;
    cout<<ansmax<<endl;
    return 0;
}