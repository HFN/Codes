// SGU 397 Text Editor
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
const int MAX = 1000005;
struct node
{
	char value;
	int unused;
	node* left;
	node* right;
	bool is_left;
	bool is_right;
	void insert_right(node &n)
	{
		if (!this->is_right)
		{
			n.left = this;
			this->right = &n;
			n.is_left = true;
			this->is_right = true;
		}
		else
		{
			node &m = *(this->right);
			m.left = &n;
			this->right = &n;
			n.left = this;
			n.right = &m;
			n.is_right = true;
			n.is_left = true;
		}
	}
} n[MAX];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int size = 1;
	node* now;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'L')
			if (now->is_left)
				now = now->left;
		if (s[i] == 'R')
			if (now->is_right)
				now = now->right;
	 if ((s[i] != 'L') && (s[i] != 'R'))
		{
			n[size].value = s[i];
			now->insert_right(n[size]);
			now = now->right;
			size++;
		}
	}
	while (now->is_left)
		now = now->left;
	while (now->is_right)
	{
		cout << now->right->value;
		now = now->right;
	}
	return 0;
}
