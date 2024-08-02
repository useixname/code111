#include <bits/stdc++.h>
using namespace std;
 
long long n;
int tot = -1;
 
void dfs(long long m) {
    if (m > n) {
        return;
    }
    tot++;
    dfs(m * 10 + 4);
    dfs(m * 10 + 7);
}
 
int main() {
    cin >> n;
    dfs(0);
    cout << tot << "\n";
    return 0;
}