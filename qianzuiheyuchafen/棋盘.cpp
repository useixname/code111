#include<iostream>
using namespace std;

const int N =1010;

int a[N][N],b[N][N];
int n, m;

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 +1] -= c;
    b[x2 +1][y2+1] +=c;
}


int main()
{
    scanf("%d %d", &n, &m);
            
    while( m-- )
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1>> x2 >> y2;
        insert(x1,y1, x2, y2, 1);
    }
    
    //ÇóÇ°×ººÍ
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= n; j++){
            b[i][j] += b[i-1][j] +b[i][j-1] -b[i-1][j-1];
            if(b[i][j]%2==0){
                cout<<0;
            }
            else{
                cout<<1;
            }
        }
        cout<<endl;
    }
    return 0;
}
