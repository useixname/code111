#include <iostream>
#include <vector>
typedef long long ll;
ll golombSequence(ll n) {
    if (n == 1) return 1;

    // 创建一个长度为 n+1 的数组 G
    std::vector<ll> G(n + 1);
    G[1] = 1;

    for (ll i = 2; i <= n; ++i) {
        G[i] = 1 + G[i - G[G[i - 1]]];
    }

    return G[n];
}

int main() {
    ll n;
    std::cin >> n;

    std::cout << golombSequence(n) << std::endl;

    return 0;
}
