// SGU 179 Brackets light
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define x first
#define y second
using namespace std;
const ll LONGINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1000000007;
const int MAX = 10005;
int dp[MAX];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++)
	{
		dp[i] = dp[i - 1];
		dp[i] += (s[i - 1] == '(') ? 1 : -1;
	}
	for (int i = s.length() - 1; i >= 0; i--)
		if ((s[i] == '(') && (dp[i] > 0))
		{
			for (int j = 0; j < i; j++)
				cout << s[j];
			cout << ')';
      			int t = (s.length() - dp[i] - i) / 2;
			for (int j = 0; j < t; j++, i++)
				cout << '(';
			i++;
			for (; i < s.length(); i++)
				cout << ')';
			return 0;
		}
	cout << "No solution";
	return 0;
}
