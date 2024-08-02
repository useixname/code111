/*输入一个 n 行 m 列的整数矩阵，再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。

对于每个询问输出子矩阵中所有数的和。

输入格式

第一行包含三个整数 n，m，q。

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含四个整数 x1,y1,x2,y2，表示一组询问。

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];//读入数组
int s[N][N];//前缀和数组
int main(){
    int m,n,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            s[i][j] = s[i][j-1] + s[i-1][j] -s[i-1][j-1] + a[i][j];//预处理前缀和
        }
    }

    while(q--){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);//求解任意子矩阵和
    }
    system("pause");
    return 0;
}

