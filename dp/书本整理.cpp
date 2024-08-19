#include<bits/stdc++.h>
using namespace std;

int n, k, m, Min = 0x7fffffff;
int f[501][501];
//f[i][l]：以i作末尾，选了l本书时的最小花费

struct info
{
	int h, w;
}a[1001];

bool cmp(const info & x, const info & y)
{
	return x.h < y.h;
}

int main()
{
	cin >> n >> k;
	m = n - k;
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].h, &a[i].w);
		
	sort(a+1, a+n+1, cmp);
	
	memset(f, 20, sizeof(f));
	for(int i = 1; i <= n; i++)
		f[i][1] = 0;

	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i-1; j++)
			for(int l = 2; l <= min(i, m); l++)
				f[i][l] = min(f[i][l], f[j][l-1] + abs(a[i].w - a[j].w));
		
	for(int i = m; i <= n; i++)
		Min = min(Min, f[i][m]);
	
	printf("%d\n", Min);
	return 0;
}