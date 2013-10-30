// Timus 1732 Ministry of Truth
#include <iostream>
using namespace std;
const int MAX = 200000;
long long par[MAX], p727[MAX];
string s, t;
void init()
{
	p727[0] = 1;
	for (int i = 1; i < MAX; i++)
		p727[i] = p727[i - 1] * 727;
	for (int i = 1; i <= s.length(); i++)
		par[i] = par[i - 1] * 727 + s[i - 1];
}
long long sum(int l, int r)
{
	return par[r] - par[l] * p727[r - l];
}
int find(int pos)
{
	pos += t.length();
	long long hash = 0;
	for (int i = 0; i < t.length(); i++)
		hash = hash * 727 + t[i];
	for (; pos <= s.length(); pos++)
		if (sum(pos - t.length(), pos) == hash)
			return pos - t.length();
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	getline(cin, s);
	init();
	string ans = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ')
			ans += ' ';
		else
			ans += '_';
	int pos = 0;
	while (cin >> t)
	{
		pos = find(pos);
		if (pos == -1)
		{
			cout << "I HAVE FAILED!!!" << endl;
			return 0;
		}
		for (int i = pos; i < pos + t.length(); i++)
			ans[i] = s[i];
		pos += t.length();
		pos++;
	}
	cout << ans << endl;
	return 0;
}
