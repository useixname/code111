#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[16005],f[16005],ans=-2147483647;
vector <int> E[16005];
void dfs(int u,int fa)
{
    f[u]=a[u];//f��ʼֵ
    for(int i=0;i<E[u].size();i++)
    {
        int t=E[u][i];
        if(t!=fa)
        {
            dfs(t,u);
            if(f[t]>0)
                f[u]+=f[t];//��ʽ
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);//��Ȩ����
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);//vector˫������
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);//�ҳ�����Ȩ��
    printf("%d",ans);
    return 0;
}