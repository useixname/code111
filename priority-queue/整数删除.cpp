//����ɾ�������ȶ��� + ģ������
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5 + 10;
int a[N], l[N], r[N];
int st[N];
void solve()
{
	int n, k; cin >> n >> k;
	priority_queue<pii, vector<pii>, greater<pii>>q;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		q.push({a[i], i});

		st[i] = a[i];

		l[i] = i - 1;
		r[i] = i + 1;
		
		if(r[i] == n)
			r[i] = -1;
	}

	int cnt = k;
	while(k)
	{
		pii t = q.top();

		q.pop();

		if(t.first != st[t.second])
		{
			q.push({st[t.second], t.second});
			continue;
		}

		k --;

		//��ȡ��Ԫ����ԭ�����е�λ��
		int pos = t.second;

		//����Ԫ�ص�����Ԫ�ؼ��ϸ���ֵ
		if(l[pos] >= 0)
		    st[l[pos]] += t.first;

		if(r[pos] >= 0)
		    st[r[pos]] += t.first;


		//�������ڵ������Ԫ��
		if(l[pos] >= 0)
		    r[l[pos]] = r[pos];
		if(r[pos] >= 0)
		    l[r[pos]] = l[pos];

		//��Ԫ���Ѿ���ɾ��������
		st[pos] = -1;
	}
	for(int i = 0; i < n; i ++)
	{
		if(st[i] != -1)
			cout << st[i] << " ";
	}
	
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)
	solve();
}
