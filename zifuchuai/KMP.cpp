#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000010;
int m, n;
char S[N], P[N];
int ne[N];

int main(){
    cin >> S+1 >> P+1;
    m = strlen(S+1), n = strlen(P+1);
    // next����
    ne[1] = 0;
    for(int i = 2, j = 0; i <= n; i ++){
        while(j && P[i] != P[j+1]) j = ne[j];
        if(P[i] == P[j+1]) ne[i]=++j; 
        // ne[i] = j;
    }
    // KMP
    for(int i = 1, j = 0; i <= m; i ++){
        while(j && S[i] != P[j+1]) j = ne[j];
        if(S[i] == P[j+1]) j ++;
        if(j == n) printf("%d\n", i-n+1);
    }
    for(int i = 1; i <= n; i ++)
        printf("%d ", ne[i]);
    return 0;
}