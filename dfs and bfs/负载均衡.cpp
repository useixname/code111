/*
    ���ݷ�Χ200,���Բ��ñ���
*/

#include<iostream>

using namespace std;

const int N=210;

int n;
int w[N],cnt; //�ֺ��ʯ�Ѻ�����
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

//�������з���
void DFS()
{
    if(cnt>m) m=cnt,d=getd();
    else if(cnt==m) d=min(d,getd());

    if(cnt==1) //ֻ��һ��ʯ�ѵ����
    {
        int a=w[0]; 
        for(int x=a/3+1;x<=a/2;x++)
        {
            w[0]=x,w[cnt++]=a-x;
            DFS();
            w[0]=a,cnt--; //�ָ��ֳ�
        }
    }
    else //����һ�ѵ����
    {
        int i=0,j=-1; //ö�ٳ����Ѻʹδ��
        for(int k=1;k<cnt;k++)
        {
            if(w[k]>=w[i]) j=i,i=k; //��������
            else if(j==-1||w[k]>w[j]) j=k; //���ڴδ��
        }

        int a=w[i],b=w[j];
        if(a!=b) // ������δ�Ѳ���ͬ���ܼ���
        {
            for(int x=max(a/3,b/2)+1;x<=a/2;x++)
            {
                w[i]=x,w[cnt++]=a-x;
                DFS();
                w[i]=a,cnt--; //�ָ��ֳ�
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