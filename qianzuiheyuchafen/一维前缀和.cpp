/*输入一个长度为 n 的整数序列。

接下来再输入 m 个询问，每个询问输入一对 l,r。

对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。*/

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
