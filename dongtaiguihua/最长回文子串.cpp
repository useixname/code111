#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
        vector<vector<int>> dp(n, vector<int>(n));
        // ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // ���ƿ�ʼ
        // ��ö���Ӵ�����
        for (int L = 2; L <= n; L++) {
            // ö����߽磬��߽���������ÿ��Կ���һЩ
            for (int i = 0; i < n; i++) {
                // �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
                int j = L + i - 1;
                // ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main(){
    Solution soveld;
    cin>>s;
    cout<<soveld.longestPalindrome(s);
}