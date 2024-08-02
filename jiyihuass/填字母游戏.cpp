#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map <string, int> mp;
string str;
int race() {
    if (mp.count(str)) return mp[str];
    if (str.find("LOL") != -1) return -1; // ���ǰһ����������ˣ��Ǿ�����
    if (str.find("*") == -1) return 0; // ���û�����ˣ��Ǿ�ƽ��
    bool flag = false;
    for (int i = 0; i < str.size(); i++) { // �����ǵô�0��ʼ
        if (str[i] == '*'){ // ������
            str[i] = 'L'; // �� L �����
            int ans = race(); // ����
            str[i] = '*';
            if (ans == -1) return mp[str] = 1;
            else if (ans == 0) flag = true;
            str[i] = 'O'; // �� O �����
            ans = race(); // ������
            str[i] = '*';
            if (ans == -1) return mp[str] = 1; // ʤ��
            else if (ans == 0) flag = true; // ƽ��
        }
    }
    if (flag) return mp[str] = 0; // //������L������O������Ӯ���䣬�Ǿ���ƽ�֡�
    return mp[str] = -1; // ����
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        if (str.size() < 3) { // ��ôС������ӣ�
        	puts("0");
        	continue;
        }
        cout << race() << '\n'; // ������ '\n'��������Ϊ endl ������
    }
}