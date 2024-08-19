#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];//01���� 
int res[1001][1001];//������ 
int lin[1000001][2];//��ʱ���������� 
int n, m, pl;//pl�ǵ�ǰ������ͨ�ĵ��� 
int b[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //���������ķ�������ѣ�������

void dfs(int x, int y){
    pl++;//����һ���µĵ㣬����洢�õ����� 
    lin[pl][0] = x; 
    lin[pl][1] = y;
    res[x][y] = 1;//������Ѿ��߹��ˣ�ֻ��Ϊ�˷�ֹһ�������ڲ����ظ��㣬���Բ���Ҫ��Ϊpl 
    for(int i = 0; i <= 3; i++){
        int u = x + b[i][0];//[u][v]��ΪĿ�ĵ� 
        int v = y + b[i][1];
        if(u < 1 || u > n || v < 1 || v > n)//�����߽磿 
            continue;
        if(res[u][v] > 0) continue;//�ߵ����� �� 
        if(a[u][v] == a[x][y]) continue;//�������⣬�������ߣ� 
        dfs(u, v);//������������������������� 
    }
}

int main(){
    memset(res, 0, sizeof(res));//��մ����� 
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%1d", &a[i][j]);//%1d�����ֿ����뷽�� 
    for(int i = 1; i <= m; i++){
        pl = 0;//����pl 
        int x, y;
        scanf("%d %d", &x, &y);
        if(res[x][y] > 0){//�Ѿ��д� 
            printf("%d\n", res[x][y]);
            continue;
        }
        dfs(x, y);
        for(int j = 1; j <= pl; j++)
            res[lin[j][0]][lin[j][1]] = pl; //�����������飬Ϊ����������pl 
        printf("%d\n", pl);
    }
    return 0;
}