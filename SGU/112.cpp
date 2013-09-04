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
string sum(string a, string b)
{
       string c;
       for (int i = a.size() - 1; i > 0; i--)
           a[i] = a [i - 1];
       a[0] = (char)"0";
       for (int i = b.size() - 1; i > 0; i--)
           b[i] = b [i - 1];
       b[0] = '0';
       while (a.size() > b.size())
       {
             for (int i = b.size() - 1; i > 0; i--)
                 b[i] = b [i - 1];
             b[0] = '0';
       }
       for (int i = 0; i < a.size(); i++)
           c[i] = '0';
       for (int i = a.size() - 1; i > 0; i--)
       {
           c[i] = (char)(((int)c[i] + (int)a[i] + (int)b[i]) % 10);
           c[i - 1] = (char)(((int)c[i] + (int)a[i] + (int)b[i]) / 10);
       }
       return c;
}
int main()
{
	ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    cout << sum(a, b);
    return 0;
}
