// SGU 276 Andrew's Troubles
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int s, p;
	cin >> s >> p;
	if (p - s >= 1800)
	{
		cout << 4;
		return 0;
	}
	if (p - s >= 900)
	{
		cout << 3;
		return 0;
	}
	if (p - s >= 300)
	{
		cout << 2;
		return 0;
	}
	if (p - s >= 1)
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
