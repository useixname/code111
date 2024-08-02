/*
    数据范围200,可以采用爆搜
*/

#include<iostream>

using namespace std;

const int N=210;

int n;
int w[N],cnt; //分后的石堆和数量
int m,d;

int getd()
{
    int MAX=0,MIN=210;
    for(int i=0;i<cnt;i++)
    {
        MAX=max(MAX,w[i]);
        MIN=min(MIN,w[i]);
    }

    return MAX-MIN;
}

//爆搜所有方案
void DFS()
{
    if(cnt>m) m=cnt,d=getd();
    else if(cnt==m) d=min(d,getd());

    if(cnt==1) //只有一个石堆的情况
    {
        int a=w[0]; 
        for(int x=a/3+1;x<=a/2;x++)
        {
            w[0]=x,w[cnt++]=a-x;
            DFS();
            w[0]=a,cnt--; //恢复现场
        }
    }
    else //不仅一堆的情况
    {
        int i=0,j=-1; //枚举出最大堆和次大堆
        for(int k=1;k<cnt;k++)
        {
            if(w[k]>=w[i]) j=i,i=k; //大于最大堆
            else if(j==-1||w[k]>w[j]) j=k; //大于次大堆
        }

        int a=w[i],b=w[j];
        if(a!=b) // 最大堆与次大堆不相同才能继续
        {
            for(int x=max(a/3,b/2)+1;x<=a/2;x++)
            {
                w[i]=x,w[cnt++]=a-x;
                DFS();
                w[i]=a,cnt--; //恢复现场
            }
        }
    }
}
int main()
{
    cin>>n;
    w[cnt++]=n;

    DFS();

    cout<<m<<' '<<d<<endl;
    return 0;
}