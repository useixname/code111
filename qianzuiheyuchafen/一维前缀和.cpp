/*����һ������Ϊ n ���������С�

������������ m ��ѯ�ʣ�ÿ��ѯ������һ�� l,r��

����ÿ��ѯ�ʣ����ԭ�����дӵ� l �������� r �����ĺ͡�*/

#include<iostream>
#include <string.h>
using namespace std;

const int N=1e5;
int a[N];
int sum[N];
int n,m;

int qianzhuihe(int *nums,int l,int r){
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1]+a[i];
    }
    return sum[r]-sum[l]+a[l];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<qianzhuihe(a,l,r)<<endl;
    }
}
