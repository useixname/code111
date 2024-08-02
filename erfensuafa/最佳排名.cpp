#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

unordered_map<string, vector<int>> mp;  // 学生--成绩
vector<int> grades[4];   // 四门课程所有成绩
char names[] = "ACME";

int get_rank(const vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(v[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return v.size() - l;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // 输入
    for(int i = 0; i < n; i++)
    {
        string id;
        int temp[4] = {0}; // ~~初始化
        cin >> id;
        for(int i = 1; i <= 3; i++)
        {
            cin >> temp[i];
            temp[0] += temp[i];
        }
        temp[0] = round(temp[0]/3.0);  // 四舍五入取成绩

        for(int i = 0; i < 4; i++)
        {
            mp[id].push_back(temp[i]);  // 学生的四门成绩映射
            grades[i].push_back(temp[i]);  // 每一门课程
        }
    }

    // 排序
    for(int i = 0; i < 4; i++)
        sort(grades[i].begin(), grades[i].end());

    // 查询
    while(m--)
    {
        string id;
        cin >> id;
        if(mp.find(id) == mp.end())
        {
            cout << "N/A" << endl;
        }
        else
        {
            // 找最高排名
            int ans = n + 1; // max
            char c;
            for(int i = 0; i < 4; i++)  // 四门课程
            {
                int r = get_rank(grades[i], mp[id][i]);
                if(r < ans)
                {
                    ans = r;
                    c = names[i];
                }
            }
            cout << ans << " " << c << endl;
        }
    }
    return 0;
}
