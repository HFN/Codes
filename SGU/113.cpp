// SGU 113 Nearly prime numbers
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
bool isNP (int n)
{
    bool ans = false;
    int c = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            n /= i;
            ans = true;
            break;
        }
    if (ans)
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
            {
                ans = false;
                break;
            }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, k[10];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
    if (isNP(k[i]))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
