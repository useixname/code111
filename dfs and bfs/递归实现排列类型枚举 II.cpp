#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
int a[N], nums[N];          //a�����������飬 nums���������
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
            dfs(u + 1);         //�ݹ��1
            st[i] = false;      //��ԭ�ֳ�

            while (i + 1 < n && a[i + 1] == a[i]) i ++ ;        //�����ظ�,����ͼ
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a, a + n);     //������ظ������־ͻ�����һ�𣬱���ȥ��

    dfs(0);

    return 0;
}