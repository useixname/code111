#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int n,num[100100],lis[100100],len;
    while(scanf("%d",&n)!=EOF)
    {
        len = 0;
        memset(lis,0,sizeof(lis));
	    for(int i=0;i<n;i++)//如果i是从1开始，在lower_bound中的到的位置会返回到0，这样就不可以把lis[1]的位置替换掉，从而WA。
        {
            scanf("%d",&num[i]);
        }
        lis[0] = num[0];
        for(int i=1;i<n;i++)
        {
            if(num[i] > lis[len])//如果num比lis[len]选择的终点大，则可以放入lis，即新的终点。
                lis[++len] = num[i]; 
            else
            {
                int pos = upper_bound(lis,lis+len,num[i]) - lis;//注意upper_bound 的用法，upper_bound返回的是第一个比它大的数的一个地址
                lis[pos] = num[i];//！！！
            }
        }
        printf("%d\n",len+1);//len是从0开始的，所以要加上1。
    }
}

