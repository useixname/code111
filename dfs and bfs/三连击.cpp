# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int x1, x2, x3;
	do {
		x1 = 100 * a[0] + 10 * a[1] + a[2];
		x2 = 100 * a[3] + 10 * a[4] + a[5];
		x3 = 100 * a[6] + 10 * a[7] + a[8];
		if (x2 == 2 * x1 && x3 == 3 * x1) {
			cout << x1 << " " << x2 << " " << x3 << endl;
		}
	} while (next_permutation(a, a + 9));
	return 0;
}