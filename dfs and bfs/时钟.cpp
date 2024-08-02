#include<iostream>
#include<vector>
using namespace std;

int a[10];
vector<int>ans,path;
string ops[9] = {
    "ABDE", "ABC", "BCEF", "ADG", "BDEFH",
    "CFI", "DEGH", "GHI", "EFHI"
};

void rotate(int x)
{
    for(auto t:ops[x-1])
    {
        int k=t-'A'+1;
        a[k]+=3;
        if(a[k]==15)a[k]=3;
    }
}

bool check()
{
    for(int i=1;i<=9;i++)
    {
        if(a[i]!=12)return 0;
    }
    return 1;
}

void dfs(int x)
{
    if(x==10)
    {
        if(check())
        {
            if(ans.empty()||ans.size()>path.size()||(ans.size()==path.size()&&ans>path))ans=path;
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        dfs(x+1);
        path.push_back(x);
        rotate(x);
    }
    for(int i=0;i<4;i++)
    {
        path.pop_back();
    }
}

int main()
{
    for(int i=1;i<=9;i++)cin>>a[i];
    dfs(1);
    for(auto k:ans)cout<<k<<' ';
    return 0;
}