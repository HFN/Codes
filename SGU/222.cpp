// SGU 222 Little Rooks
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
int fact(int n)
{
    if (n == 0)
       return 1;
    return n * fact(n - 1);
}
int main()
{
	ios::sync_with_stdio(false);
    ll n, k, c = 1;
    cin >> n >> k;
    if (k == 0)
       cout << 1;
    else
        if (k > n)
           cout << 0;
        else
        {
            for (int i = n; i > n - k; i--)
                c *= i * i;
            cout << c / fact(k);
        }
    return 0;
}
