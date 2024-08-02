#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define int long long
const int N = 1010;

int a[N];
int tmp[N];
int n,m;

bool check(int k){
    memcpy(tmp,a,sizeof tmp);
    sort(tmp+1,tmp+1+k);
    int t = m;
    reverse(tmp+1,tmp+1+k);
    for(int i=1;i<=k;i+=2){
        t-=tmp[i];
        if(t<0){
            return false;
        }
    }
    return true;
}
//��Ϊ�������ҵ�����k֮���ٴ��һ�������ˣ�
//��С�����k�Ĺ�����һ������ȫ������ģ�������һ�������ǿ����뵽�ö�������
signed main()
{

    cin>>n>>m;
    for (int i = 1; i<=n;i++)   cin>>a[i];
    int l = 1;int r = n;
    while(l<r){
        int mid = (l+r+1) >>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
    return 0;
}


