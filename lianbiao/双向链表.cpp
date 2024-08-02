#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define ts first
#define id second
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII q[N]; // ���桰���ޡ���־
int cnt[N]; // ��¼ D ����ĵ�����
set<int> s; // ������� id
int n, d, k;
int main()
{
    cin >> n >> d >> k;
    for (int i = 0; i < n; i ++ )   scanf("%d%d", &q[i].ts, &q[i].id);
    sort(q, q + n); // �����ޡ���־�� ts ʱ���С��������    
    for (int i = 0, j = 0; i < n; i ++ )
    {
        //cout<<q[i].ts<<" "<<q[i].id<<endl;
        int t = q[i].id;
        cnt[t] ++ ; // ��¼��ʱ�̵� id
        while (q[i].ts - q[j].ts >= d) // ���� D ���䣬
        {
            cnt[q[j].id] -- ; // �������ڡ�ʱ�̵��� id ȥ��
            j ++ ; // ���¸�ʱ����
        }
        if (cnt[t] >= k) s.insert(t); // ��¼�������ڷ��ϵ� id
    }
    for (auto t : s)
        printf("%d\n", t);
    return 0;
}