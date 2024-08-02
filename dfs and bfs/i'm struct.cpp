#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
char g[N][N];//�����ͼ
bool st1[N][N], st2[N][N];// ��¼�ɴ���
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};//���������ĸ�����

bool check(int x, int y, int k)//�ж� x, y �Ƿ����ߵ�����Ϊ k ���Ǹ��㡣k = 0, 1, 2, 3 �ֱ�������ϣ��������£�������
{
    if(g[x][y] == 'T' || g[x][y] == '+' || g[x][y] == 'S') return true;// T, +, S ���ߵ���������
    if(g[x][y] == '.' && k == 2) return true;// . ֻ�������� 
    if(g[x][y] == '-' && (k == 1 || k == 3)) return true;// - ����������
    if(g[x][y] == '|' && (k == 0 || k == 2)) return true;// | ����������
    return false;
}

void dfs1(int x, int y)//������ȱ�������� S �ܵ������е�
{
    st1[x][y] = true;//���ߵ���ǰ�㣬״̬��Ϊ true
    for(int i = 0; i < 4; i++)//��4��������
    {
        int a = x + dx[i], b = y + dy[i];
        if(check(x, y, i) && !st1[a][b] && g[a][b] != '#')//�����ǰλ�����ߵ���һλ�ã�������һλ��û���߹������Ҳ��� #���ߵ���һλ��
            dfs1(a, b);
    }
}

void dfs2(int x, int y)//������ȱ�����������ߵ� T �����е�
{
    st2[x][y] = true;//��ǰ�����߻أ�״̬��Ϊ true
    for(int i = 0; i < 4; i++)//�ĸ�������ǰ����
    {
        int a = x + dx[i], b = y + dy[i];
        int k = i ^ 2;//ĳ�����ܷ��ߵ� x��y, �� x, y �ߵ��õ㷽���෴��0 -> 2, 1 -> 3, 2 -> 0, 3 -> 1�� 
        if(check(a, b, k) && !st2[a][b] )
            dfs2(a, b);
    }
}

int main()
{
    int n, m;
    int s_x, s_y, e_x, e_y;// s_x, s_y����¼ S ��λ�ã�e_x, e_yT����¼ T ��λ�á�
    cin >> n >> m;
    memset(g,'#',sizeof(g));//��ʼ״̬ȫ��Ϊǽ


    for(int i = 1; i <= n; i++)// �� 1 1 ��ʼ�洢�����Ա���߽紦��
    {
        for(int j = 1; j<= m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S')// �ҵ� S 
                    s_x = i, s_y = j;
                if(g[i][j] == 'T')// �ҵ� T
                    e_x = i, e_y = j;
            }
    }

    dfs1(s_x, s_y);//��� S ���ߵ������е�

    if(!st1[e_x][e_y])// S �����ߵ� T
    {
        cout << "I'm stuck!";
        return 0;
    }

    dfs2(e_x, e_y);//������ߵ� T �����е�

    int res = 0;

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(st1[i][j] && !st2[i][j])// S �ܵ� g[i][j], g[i][j] ���ܵ� T
                res++;
        }
    }
    cout << res;

}