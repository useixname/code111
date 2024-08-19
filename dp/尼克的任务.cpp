#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,s,t,f[10002];
vector<int>v[10001];
int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        scanf("%d%d",&s,&t);
        v[s].push_back(t);
    }
    for(int i=n;i;--i){
        if(v[i].size()>0)
            for(int j=0;j<v[i].size();++j)
                f[i]=max(f[i],f[i+v[i][j]]);
        else f[i]=f[i+1]+1;            
    }
    printf("%d",f[1]);
}