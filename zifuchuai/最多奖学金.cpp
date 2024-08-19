#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x = 0, sum = 0, b, c, f;
    char d, e;
    string a, name;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        cin >> a >> b >> c >> d >> e >> f;
        if (b > 80 && f > 0)
            s += 8000;
        if (b > 85 && c > 80)
            s += 4000;
        if (b > 90)
            s += 2000;
        if (e == 'Y' && b > 85)
            s += 1000;
        if (d == 'Y' && c > 80)
            s += 850;
        sum += s;
        if (x < s)
        {
            x = s;
            name = a;
        }
    }
    cout << name << endl;
    cout << x << endl;
    cout << sum;
    return 0;
}