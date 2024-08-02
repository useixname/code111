#include <iostream>
using namespace std;

// ������������ n ��5�����ӵ�����
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
