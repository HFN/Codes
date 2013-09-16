// SGU 269 Rooks
#include <algorithm>
#include <iostream>
#include <BIGnum.h>
using namespace std;
const int MAX = 300;
BIGnum dp[MAX][MAX];
int a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < MAX; i++)
		dp[i][0] = 1;
	dp[0][1] = a[0];
	for (int r = 1; r < n; r++)
		for (int i = 1; i <= k; i++)
			dp[r][i] = dp[r - 1][i] + dp[r - 1][i - 1] * max(0, a[r] - (i - 1));
	cout << dp[n - 1][k];
	return 0;
}
