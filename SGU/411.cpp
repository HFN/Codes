// SGU 411 Petya the Hero
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int MAX = 5000;
long long hashl[MAX], hashr[MAX], p727[MAX];
set<long long> mark;
int main()
{
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	p727[0] = 1;
	for (int i = 1; i < MAX; i++)
		p727[i] = p727[i - 1] * 727;
	for (int i = 1; i <= s.length(); i++)
		hashl[i] = hashl[i - 1] * 727 + s[i - 1];
	for (int i = s.length() - 1; i >= 0; i--)
		hashr[i] = hashr[i + 1] * 727 + s[i];
	for (int l = 0; l < s.length(); l++)
		for (int r = l + 1; r <= s.length(); r++)
			if (hashl[r] - hashl[l] * p727[r - l] == hashr[l] - hashr[r] * p727[r - l])
				mark.insert(hashl[r] - hashl[l] * p727[r - l]);
	memset(hashl, 0, sizeof(hashl));
	memset(hashr, 0, sizeof(hashr));
	for (int i = 1; i <= t.length(); i++)
		hashl[i] = hashl[i - 1] * 727 + t[i - 1];
	for (int i = t.length() - 1; i >= 0; i--)
		hashr[i] = hashr[i + 1] * 727 + t[i];
	pair<int, int> ans = make_pair(0, 0);
	for (int l = 0; l < t.length(); l++)
		for (int r = l + 1; r <= t.length(); r++)
			if (hashl[r] - hashl[l] * p727[r - l] == hashr[l] - hashr[r] * p727[r - l] && mark.count(hashl[r] - hashl[l] * p727[r - l]) && ans.second - ans.first < r - l)
				ans = make_pair(l, r);
	for (int i = ans.first; i < ans.second; i++)
		cout << t[i];
	return 0;
}
