#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map <string, int> mp;
string str;
int race() {
    if (mp.count(str)) return mp[str];
    if (str.find("LOL") != -1) return -1; // 如果前一步有人填好了，那就输了
    if (str.find("*") == -1) return 0; // 如果没得填了，那就平了
    bool flag = false;
    for (int i = 0; i < str.size(); i++) { // 遍历记得从0开始
        if (str[i] == '*'){ // 可以填
            str[i] = 'L'; // 填 L 的情况
            int ans = race(); // 搜索
            str[i] = '*';
            if (ans == -1) return mp[str] = 1;
            else if (ans == 0) flag = true;
            str[i] = 'O'; // 填 O 的情况
            ans = race(); // 继续搜
            str[i] = '*';
            if (ans == -1) return mp[str] = 1; // 胜了
            else if (ans == 0) flag = true; // 平了
        }
    }
    if (flag) return mp[str] = 0; // //无论填L还是填O都不能赢或输，那就是平局。
    return mp[str] = -1; // 败了
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        if (str.size() < 3) { // 这么小填个锤子！
        	puts("0");
        	continue;
        }
        cout << race() << '\n'; // 建议用 '\n'，个人认为 endl 不好用
    }
}