// SGU 126 Boxes
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
const int INF = 1000000;
const int MOD = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    int a, b, c = 0;
    cin >> a >> b;
    while ((a != 0) && (b != 0))
    {
	c++;
	if (a > b)
	{
	    a -= b;
	    b += b;
	}
	else     
	{
	    b -= a;
	    a += a;
	}
	if (c == INF)
	    break;
    }
    if (c != INF)
    	cout << c;
    else 
        cout << -1;
    return 0;
}
