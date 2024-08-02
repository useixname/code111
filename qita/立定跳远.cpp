#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int n, m;
bool check(int mid)
{
    int cnt = m;
    for (int i = 1; i < n; i++)
    {
        int t = a[i] - a[i - 1];
        if (mid < t)
        {
            if (t % mid == 0)
            {
                cnt -= (t / mid - 1);
                if (cnt < 0) return false;
            }
            else
            {
                cnt -= (t / mid);
                if (cnt < 0) return false;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    m++;//能跳一次2倍的距离，所以m++。
    int l = 1, r = 1e8 + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return 0;
}