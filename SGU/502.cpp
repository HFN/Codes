// SGU 502 Digits Permutation
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	vector<int> digits;
	while (n > 0)
	{
		digits.push_back(n % 10);
		n /= 10;
	}
	sort(digits.begin(), digits.end());
	for (int i = 0; i < digits.size(); i++)
		if (digits[i] != 0)
		{
			swap(digits[0], digits[i]);
			break;
		}
	do
	{
		n = 0;
		for (int i = 0; i < digits.size(); i++)
			n = n * 10 + digits[i];
		if (n % 17 == 0)
		{
			cout << n;
			return 0;
		}
	} while (next_permutation(digits.begin(), digits.end()));
	cout << -1;
	return 0;
}
