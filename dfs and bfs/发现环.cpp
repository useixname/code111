#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int>G[maxn];
int fa[maxn];
int n;
int sx, fy;
bool vis[maxn];
int res[maxn];
int find(int x){
   return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void dfs(int x, int len){
   res[len] = x;
   if(x == fy){
       sort(res, res + len + 1);
       for (int i = 0; i <= len; ++i) {
           printf("%d ", res[i]);
       }
       cout << endl;
       //return ;
   }
   vis[x] = 1;
   for (int i = 0; i < G[x].size(); ++i) {
       if(!vis[G[x][i]]){
           dfs(G[x][i], len + 1);
       }
   }
   vis[x] = 0;
}
int main(){
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
       fa[i] = i;
   }
   for (int i = 1; i <= n; ++i) {
       int x, y;
       scanf("%d%d", &x, &y);
       int p1 = find(x);
       int p2 = find(y);
       if(p1 != p2) {
           fa[p2] = p1;
           G[x].push_back(y);
           G[y].push_back(x);
       }else {
           sx = x;
           fy = y;
       }
   }
   dfs(sx, 0);
   return 0;
}