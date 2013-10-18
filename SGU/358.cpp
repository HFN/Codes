// SGU 358 Median of Medians
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a[3], b[3], c[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	for (int i = 0; i < 3; i++)
		cin >> b[i];
	for (int i = 0; i < 3; i++)
		cin >> c[i];
	sort(a, a + 3);
	sort(b, b + 3);
	sort(c, c + 3);
	a[0] = a[1];
	a[1] = b[1];
	a[2] = c[1];
	sort(a, a + 3);
	cout << a[1];
	return 0;
}
