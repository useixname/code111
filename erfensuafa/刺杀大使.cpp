#include<bits/stdc++.h>
using namespace std;

int get()
{
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int MaxN = 1005;
const int inf = 0x3f3f3f3f;
const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {0, 0, 1, 0, -1};
int p[MaxN][MaxN], vis[MaxN][MaxN];
int n, m;
int l = inf, r = -inf, mid, ans, f; 

bool bfs(int x, int y, int maxn) //�ж�mid�Ƿ���е�bfs
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y)); //STL���pair��������ΪҪ����һЩ
	vis[x][y] = 1; 
	while(q.size()) { //���¾���bfs����
		int xx = q.front().first; 
		int yy = q.front().second;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if(nx < 1 || nx > n || yy < 1 || yy > m || vis[nx][ny] || p[nx][ny] > maxn)
				continue; //�����У�Խ�硢�ѷ��ʡ��˺����󣩵�ֱ������
			vis[nx][ny] = 1;
			if(nx == n) return 1; //���ˣ�����1
			else q.push(make_pair(nx, ny));
		}
	}
	return 0; //û���ѵ�������0
}

int main()
{
	n = get(), m = get();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			p[i][j] = get();
			r = max(r, p[i][j]);
			l = min(l, p[i][j]);
		}
	}
	while(l <= r) { //���ִ�ģ��
		mid = (l + r) >> 1;
		f = 0;
		memset(vis, 0, sizeof(vis)); //��������
		if(bfs(1, 1, mid)) r = mid - 1, ans = mid; //������mid���У�˵�����ܻ�����С�����Ǹ��´� + ��С��Χ
		else l = mid + 1; //mid�˲����У�˵����������С��Ҳ��С��Χ�������´�
	}
	printf("%d", ans);
	return 0;
}