#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int a,b,n,i2=0;
    string s;
    cin>>a>>b>>n>>s;
    for(int i=1;i<=5;i++)
    {
        s[n-1]++;
        for(int q=n-1;;q--)
        {
            if(s[q]>b+96-i2)
            {
                s[q-1]++;
                if(q==0) return 0;      
            }
            else
            {
                for(int j=q+1;j<=n-1;j++)
                {
                    s[j]=s[j-1]+1;
                }
                break;
            }
            i2++;
        }
        cout<<s<<endl;
        i2=0;
    }
    return 0;
}