#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e3+10;
int n;
char a[N][N];

int main(){
    memset(a,' ',sizeof(a));
    scanf("%d",&n);
    int k=n/2+1,t=0;
    for(int i=1;i<=k;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t++;
    }
    t-=2;
    for(int i=k+1;i<=n;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}