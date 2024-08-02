#include <iostream>
using namespace std;
const int N = 110;
int a[N], cnt = 0;
bool cmp(int a[], int n) {
    for(int i =0; i < n - 1; i++) {
        if(a[i] != a[i + 1]) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++ ) cin >> a[i];
    while (!cmp(a, n)) {
        for(int i = 0; i < n; i++) a[i] /= 2;
        int c = a[0];
        for(int i = 0; i < n; i++) {
            if(i < n -1) a[i] += a[i + 1];
            else a[i] += c;
        }
        for(int i = 0; i < n; i++) {
            if(a[i] % 2) {
                a[i] += 1;
                cnt++;
            }
            
        }
    }
    cout << cnt;
  return 0;
}