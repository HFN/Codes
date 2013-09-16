// SGU 246 Black & White
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n / 2 + (n % 3 ? 1 : 0);
	return 0;
}
