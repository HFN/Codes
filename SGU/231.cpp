// SGU 231 Prime Sum
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
int sq(int n)
{
    int i = 0;
    for (i; i * i <= n; i++);
    return i;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, c = 0;
    cin >> n;
    bool b[n + 1];
    for (int i = 0; i <= n; i++)
        b[i] = true;
    for (int i = 2; i < sq(n); i++)
        if (b[i])
           for (int j = 2; j <= n / i; j++)
               b[i * j] = false;
    for (int i = 2; i < n - 1; i++)
        if ((b[i]) && (b[i + 2]))
           c++;
    cout << c << endl;
    for (int i = 2; i < n - 1; i++)
        if ((b[i]) && (b[i + 2]))
           cout << 2 << " " << i << endl;
    return 0;
}
