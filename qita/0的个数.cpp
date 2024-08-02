#include <iostream>
using namespace std;

// 函数用来计算 n 中5的因子的数量
int countFiveFactors(int n) {
    int count = 0;
    for (long long i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << countFiveFactors(N) << endl;
    }
    return 0;
}
