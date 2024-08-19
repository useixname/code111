#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];//01数组 
int res[1001][1001];//答案数组 
int lin[1000001][2];//临时的坐标数组 
int n, m, pl;//pl是当前区块连通的点数 
int b[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //上下左右四方向的深搜，很有用

void dfs(int x, int y){
    pl++;//来到一个新的点，下面存储该点坐标 
    lin[pl][0] = x; 
    lin[pl][1] = y;
    res[x][y] = 1;//这个点已经走过了，只是为了防止一趟深搜内部走重复点，所以不需要赋为pl 
    for(int i = 0; i <= 3; i++){
        int u = x + b[i][0];//[u][v]即为目的地 
        int v = y + b[i][1];
        if(u < 1 || u > n || v < 1 || v > n)//超出边界？ 
            continue;
        if(res[u][v] > 0) continue;//走到过了 ？ 
        if(a[u][v] == a[x][y]) continue;//根据题意，并不能走？ 
        dfs(u, v);//以上条件都不满足才向下搜索 
    }
}

int main(){
    memset(res, 0, sizeof(res));//清空答案数组 
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%1d", &a[i][j]);//%1d，限字宽，读入方便 
    for(int i = 1; i <= m; i++){
        pl = 0;//重置pl 
        int x, y;
        scanf("%d %d", &x, &y);
        if(res[x][y] > 0){//已经有答案 
            printf("%d\n", res[x][y]);
            continue;
        }
        dfs(x, y);
        for(int j = 1; j <= pl; j++)
            res[lin[j][0]][lin[j][1]] = pl; //依据坐标数组，为答案数组填上pl 
        printf("%d\n", pl);
    }
    return 0;
}