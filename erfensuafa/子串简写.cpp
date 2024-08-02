#include<bits/stdc++.h>
 
#define int long long
 
using namespace std;
void solve()
 
{
	int k;string s;
	char c1, c2;
	cin >> k >> s >> c1 >> c2;
	vector<int>pc1;
	int ans = 0;
	for(int i = 0; i < s.size(); i ++)
	{
	if(s[i] == c1)
	pc1.push_back(i);
	if(s[i] == c2)
	{
	    if(i - k + 1 < 0 || !pc1.size())
	        continue;
	    int l = 0, r = (int)pc1.size() - 1;
	    while(l < r)
	    {
	    int mid = (l + r + 1) >> 1;
	    if(pc1[mid] <= (i - k + 1))
	    l = mid;
	    else
	    r = mid - 1;
	    }
	    if(pc1[l] <= i - k + 1)
	    ans += (l + 1);
	}
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}