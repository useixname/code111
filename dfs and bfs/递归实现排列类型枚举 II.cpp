#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
int a[N], nums[N];          //a储存排序数组， nums是输出数组
bool st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++ ) cout << nums[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i ++ )
        if (!st[i])
        {
            nums[u] = a[i];
            st[i] = true;
            dfs(u + 1);         //递归加1
            st[i] = false;      //还原现场

            while (i + 1 < n && a[i + 1] == a[i]) i ++ ;        //跳过重复,见下图
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a, a + n);     //排序后重复的数字就会排在一起，便于去重

    dfs(0);

    return 0;
}