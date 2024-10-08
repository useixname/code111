#include <stdio.h>
int n, x, y, l, tot, ans[1050][1050], prt, k[1100000];
void dfs(int a, int b, int c, int d, int x, int y)
{
    // 正方形左上角是a行b列，右下角是c行d列,军营在x行y列
    int h = (a + c) / 2, l = (b + d) / 2;
    int p = (x > h) * 2 + (y > l);
    // p记录军营在正方形的哪个位置
    // 0表示左上，1表示右上，2表示左下，3表示右下
    if (p == 0)
        ans[h][l + 1] = ans[h + 1][l] = ans[h + 1][l + 1] = ++tot;
    else if (p == 1)
        ans[h][l] = ans[h + 1][l] = ans[h + 1][l + 1] = ++tot;
    else if (p == 2)
        ans[h][l] = ans[h][l + 1] = ans[h + 1][l + 1] = ++tot;
    else
        ans[h][l] = ans[h + 1][l] = ans[h][l + 1] = ++tot;
    if (c - a >= 3)
    {
        if (p == 0)
            dfs(a, b, h, l, x, y);
        else
            dfs(a, b, h, l, h, l);
        if (p == 1)
            dfs(a, l + 1, h, d, x, y);
        else
            dfs(a, l + 1, h, d, h, l + 1);
        if (p == 2)
            dfs(h + 1, b, c, l, x, y);
        else
            dfs(h + 1, b, c, l, h + 1, l);
        if (p == 3)
            dfs(h + 1, l + 1, c, d, x, y);
        else
            dfs(h + 1, l + 1, c, d, h + 1, l + 1);
    }
}
int main()
{
    scanf("%d%d%d", &n, &x, &y);
    l = 1 << n;
    dfs(1, 1, l, l, x, y);
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
            if (ans[i][j])
            {
                if (!k[ans[i][j]])
                    k[ans[i][j]] = ++prt;
                printf("%d ", k[ans[i][j]]);
            }
            else
                printf("0 ");
        puts("");
    }
    return 0;
}