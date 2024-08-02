#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define ts first
#define id second
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII q[N]; // 保存“点赞”日志
int cnt[N]; // 记录 D 区间的点赞数
set<int> s; // 保存点赞 id
int n, d, k;
int main()
{
    cin >> n >> d >> k;
    for (int i = 0; i < n; i ++ )   scanf("%d%d", &q[i].ts, &q[i].id);
    sort(q, q + n); // “点赞”日志按 ts 时间从小到大排序    
    for (int i = 0, j = 0; i < n; i ++ )
    {
        //cout<<q[i].ts<<" "<<q[i].id<<endl;
        int t = q[i].id;
        cnt[t] ++ ; // 记录该时刻的 id
        while (q[i].ts - q[j].ts >= d) // 大于 D 区间，
        {
            cnt[q[j].id] -- ; // 将“过期”时刻的赞 id 去掉
            j ++ ; // 往下个时间找
        }
        if (cnt[t] >= k) s.insert(t); // 记录在区间内符合的 id
    }
    for (auto t : s)
        printf("%d\n", t);
    return 0;
}