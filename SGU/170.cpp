// SGU 170 Particles
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
int main()
{
    ios::sync_with_stdio(false);
    string a, b;
    int ap = 0, bp = 0, am = 0, bm = 0, n = 0, ii, jj;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '+')
           ap++;
        else
            am++;
    for (int i = 0; i < b.size(); i++)
        if (b[i] == '+')
           bp++;
        else
            bm++;
    if ((ap != bp) || (am != bm))
       cout << -1;
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            ii = i;
            if (a[i] == '+')
               for (int j = i; b[j] == '-'; j++)
               {
                   n++;
                   jj = j;
               }
            else
                for (int j = i; b[j] == '+'; j++)
                {
                    n++;
                    jj = j;
                }
            swap(b[ii], b[jj + 1]);
        }
        cout << n;
    }
    return 0;
}
