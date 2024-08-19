#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll N = 1e5 + 9;

ll h[N];

priority_queue<ll> pq;

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, p, q, ans = 0;
    cin >> n >> p >> q;

    for (int i = 1; i <= n; i++)
    {

        cin >> h[i];

        pq.push(h[i]);
    }

    ll mx = pq.top();
    if (p || q)
        pq.pop();

    while (p || q)
    {

        if ((mx >= 6 && p) || !q)
        {
            mx = sqrt(mx);
            p--;
        }

        else if (q)
        {
            mx /= 2;
            q--;
        }

        pq.push(mx);

        mx = pq.top();
        if (p || q)
            pq.pop();
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}