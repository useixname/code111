#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

unordered_map<string, vector<int>> mp;  // ѧ��--�ɼ�
vector<int> grades[4];   // ���ſγ����гɼ�
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
    // ����
    for(int i = 0; i < n; i++)
    {
        string id;
        int temp[4] = {0}; // ~~��ʼ��
        cin >> id;
        for(int i = 1; i <= 3; i++)
        {
            cin >> temp[i];
            temp[0] += temp[i];
        }
        temp[0] = round(temp[0]/3.0);  // ��������ȡ�ɼ�

        for(int i = 0; i < 4; i++)
        {
            mp[id].push_back(temp[i]);  // ѧ�������ųɼ�ӳ��
            grades[i].push_back(temp[i]);  // ÿһ�ſγ�
        }
    }

    // ����
    for(int i = 0; i < 4; i++)
        sort(grades[i].begin(), grades[i].end());

    // ��ѯ
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
            // ���������
            int ans = n + 1; // max
            char c;
            for(int i = 0; i < 4; i++)  // ���ſγ�
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
