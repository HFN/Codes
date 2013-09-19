// SGU 281 Championship
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX = 500005;
string first[MAX], second[MAX];
void print(int i, int j)
{
	vector<string> teams;
	for (int k = i; k <= j; k++)
		teams.push_back(first[k]);
	sort(teams.begin(), teams.end());
	for (int i = 0; i < teams.size(); i++)
		cout << teams[i] << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> first[i];
	for (int i = 0; i < n; i++)
		cin >> second[i];
	set<string> s1, s2;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (s1.empty())
		{
			print(p, i - 1);
			p = i;
		}
		if (s2.count(first[i]))
			s2.erase(first[i]);
		else
			s1.insert(first[i]);
		if (s1.count(second[i]))
			s1.erase(second[i]);
		else
			s2.insert(second[i]);
	}
	print(p, n - 1);
	return 0;
}
