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
	    for(int i=0;i<n;i++)//���i�Ǵ�1��ʼ����lower_bound�еĵ���λ�û᷵�ص�0�������Ͳ����԰�lis[1]��λ���滻�����Ӷ�WA��
        {
            scanf("%d",&num[i]);
        }
        lis[0] = num[0];
        for(int i=1;i<n;i++)
        {
            if(num[i] > lis[len])//���num��lis[len]ѡ����յ������Է���lis�����µ��յ㡣
                lis[++len] = num[i]; 
            else
            {
                int pos = upper_bound(lis,lis+len,num[i]) - lis;//ע��upper_bound ���÷���upper_bound���ص��ǵ�һ�������������һ����ַ
                lis[pos] = num[i];//������
            }
        }
        printf("%d\n",len+1);//len�Ǵ�0��ʼ�ģ�����Ҫ����1��
    }
}

