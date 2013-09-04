// SGU 296 Sasha vs. Kate
#include <algorithm>
#include <iostream>
#include <cstdlib>
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
const int INF = 1000000007;
vector<int> digit;
void delete_one_digit()
{
	for (int i = 0; i < digit.size() - 1; i++)
		if (digit[i] < digit[i + 1])
		{
			digit.erase(digit.begin() + i);
			return;
		}
	digit.pop_back();
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> s >> n;
	for (int i = 0; i < s.length(); i++)
		digit.push_back(s[i] - '0'); 
	for (int i = 0; i < n; i++)
		delete_one_digit();
	for (int i = 0; i < digit.size(); i++)
		cout << digit[i];
 	return 0;
}
