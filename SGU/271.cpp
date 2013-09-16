// SGU 271 Book Pile
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
const int MAX = 50000;
deque<string> top;
stack<string> ans;
string x[MAX];
int n, m, k;
bool dir;
string name(string s)
{
	string ans = "";
	for (int i = 4; i < s.size() - 1; i++)
		ans += s[i];
	return ans;
}
void add(string s)
{
	if (dir)
	{
		top.push_back(s);
		if (top.size() > k)
		{
			ans.push(top.front());
			top.pop_front();
		}
	}
	else
	{
		top.push_front(s);
		if (top.size() > k)
		{
			ans.push(top.back());
			top.pop_back();
		}
	}
}
void complete()
{
	if (top.empty())
		return;
	if (dir)
	{
		ans.push(top.front());
		top.pop_front();
	}
	else
	{
		ans.push(top.back());
		top.pop_back();
	}
	complete();
}
void rotate()
{
	dir = !dir;
}
void print()
{
	if (ans.empty())
		return;
	cout << ans.top() << endl;
	ans.pop();
	print();
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = n - 1; i >= 0; i--)
		add(x[i]);
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s[0] == 'R')
			rotate();
		else
			add(name(s));
	}
	complete();
	print();
	return 0;
}
