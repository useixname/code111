#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[201][201],f[201][201]={0},x,y;
int main()
{
    cin>>n>>m;
    y=m/2+1;x=n;                           //������ˮţ�ʼ��λ��
    memset(a,-9999,sizeof(a));               //���ñ߽磬Ϊ�˱������ˮţ�Ե���������ȥ����
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];               //����
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];         //��̬����
        }
    }
    cout<<max(max(f[x][y],f[x][y-1]),f[x][y+1])<<endl;       //��Ϊ���ֵֻ���������ˮţ��ǰ������ǰ������ǰ��������ֻҪ������������������
    return 0;
}