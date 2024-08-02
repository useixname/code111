#include <iostream>
using namespace std;

int const N = 100010;
int w[N], h[N];//�洢������
int n, k;

bool chack(int a)
{
    int num = 0;//��¼�ֳɳ���Ϊ a ���ɿ�������
    for (int i = 0; i < n; i++)
    {
        num += (w[i] / a) * (h[i] / a);//ÿһ�����Էֳɵı߳�Ϊ a ���ɿ�������
        if (num >= k) return true;//����Ҫ��������������
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
    int l = 1, r = 1e5;//С�ɿ��������߳�һ���� 1 -- 100000 ֮��
    while (l < r)//����С�ɿ����߳���Χ���ҵ�����Ҫ������ֵ
    {
        int mid = l + (r - l + 1 >> 1);//��Ϊl = mid ������ mid ȡ l + r + 1 >> 1,Ϊ�˷�ֹ�Ӻ�Խ�磬��д�� l + (r - l + 1 >> 1)
        if (chack(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
}