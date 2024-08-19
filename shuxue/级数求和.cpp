#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	double sum=0;
	cin>>m;
	
	for(n=0;sum<=m;)
    {
	    n++;
	    sum+=(1.0/n);
    }
    cout<<n;
    return 0;
}