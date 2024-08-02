#include<iostream>
#define INF 0x7f7f7f7f

using namespace std;
int A, B, L,res_a=1,res_b=1;
double delta=INF;
bool check(double x, double y)
{
    if (x < y) return true;
    else  return false;
}

int main(int argc, char* argv[])
{
    cin >> A >> B >> L;
    for (int i = 1; i <= L; i++)
    {
        int l = 1, r = L;
        while (l <= r)
        {
            int mid = l + r >>1;
            double x = (double)i / mid;
            double y = (double)A / B;
            if (check(x, y))  r = mid;
            else l = mid + 1;
        }
        l--;
        double x = (double)i / l;
        double y = (double)A / B;
        if (x>=y &&x-y<delta) {
            delta = x-y;
            res_a = i; res_b = l;
        }
    }
    cout << res_a << ' ' << res_b << endl;
    return 0;
}