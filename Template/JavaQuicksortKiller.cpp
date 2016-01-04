#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

class JavaQuicksortKiller {
	enum { INSERTION_SORT_THRESHOLD = 47 };
	enum { NO_VALUE = -1 };

	int MIN_VALUE;
	int MAX_VALUE;
 
	unsigned rng(unsigned x) { return xor128() % x; }

	void hackedSort(int *a, int *p, int left, int right, bool leftmost) {
		int length = right - left + 1;
		if (length < INSERTION_SORT_THRESHOLD) {
			for (int i = right; i >= left; i--) {
				if (a[i] == NO_VALUE) a[i] = MIN_VALUE++;
			}
			randomShuffle(a, left, right); 
			if (leftmost) {
				for (int i = left, j = i; i < right; j = ++i) {
					int ai = a[i + 1];
					int pi = p[i + 1];
					while (ai < a[j]) {
						a[j + 1] = a[j];
						p[j + 1] = p[j];
						if (j-- == left) {
							break;
						}
					}
					a[j + 1] = ai;
					p[j + 1] = pi;
				}
			} else {
				do {
					if (left >= right) {
						return;
					}
				} while (a[++left] >= a[left - 1]);
				for (int k = left; ++left <= right; k = ++left) {
					int a1 = a[k], a2 = a[left];
					int p1 = p[k], p2 = p[left];
 
					if (a1 < a2) {
						a2 = a1; a1 = a[left];
						p2 = p1; p1 = p[left];
					}
					while (a1 < a[--k]) {
						a[k + 2] = a[k];
						p[k + 2] = p[k];
					}
					++k;
					a[k + 1] = a1;
					p[k + 1] = p1;
 
					while (a2 < a[--k]) {
						a[k + 1] = a[k];
						p[k + 1] = p[k];
					}
					a[k + 1] = a2;
					p[k + 1] = p2;
				}
				int last = a[right];
				int plast = p[right];
 
				while (last < a[--right]) {
					a[right + 1] = a[right];
					p[right + 1] = p[right];
				}
				a[right + 1] = last;
				p[right + 1] = plast;
			}
			return;
		}
		int seventh = (length >> 3) + (length >> 6) + 1;

		int e3 = (left + right) >> 1; 
		int e2 = e3 - seventh;
		int e1 = e2 - seventh;
		int e4 = e3 + seventh;
		int e5 = e4 + seventh;
 
		if (a[e5] == NO_VALUE) a[e5] = MIN_VALUE++;
		if (a[e4] == NO_VALUE) a[e4] = MIN_VALUE++;
 
		if (a[e1] == NO_VALUE) a[e1] = MAX_VALUE--;
		if (a[e2] == NO_VALUE) a[e2] = MAX_VALUE--;
 
		
		if (fless(a[e2], a[e1])) { int t = a[e2]; a[e2] = a[e1]; a[e1] = t;
								  int s = p[e2]; p[e2] = p[e1]; p[e1] = s; }
 
		if (fless(a[e3], a[e2])) { int t = a[e3]; a[e3] = a[e2]; a[e2] = t;
								  int s = p[e3]; p[e3] = p[e2]; p[e2] = s;
			if (fless(t, a[e1])) { a[e2] = a[e1]; a[e1] = t;
								  p[e2] = p[e1]; p[e1] = s; }
		}
		if (fless(a[e4], a[e3])) { int t = a[e4]; a[e4] = a[e3]; a[e3] = t;
								  int s = p[e4]; p[e4] = p[e3]; p[e3] = s;
			if (fless(t, a[e2])) { a[e3] = a[e2]; a[e2] = t;
								  p[e3] = p[e2]; p[e2] = s;
				if (fless(t, a[e1])) { a[e2] = a[e1]; a[e1] = t;
									  p[e2] = p[e1]; p[e1] = s; }
			}
		}
		if (fless(a[e5], a[e4])) { int t = a[e5]; a[e5] = a[e4]; a[e4] = t;
								  int s = p[e5]; p[e5] = p[e4]; p[e4] = s;
			if (fless(t, a[e3])) { a[e4] = a[e3]; a[e3] = t;
								  p[e4] = p[e3]; p[e3] = s;
				if (fless(t, a[e2])) { a[e3] = a[e2]; a[e2] = t;
									  p[e3] = p[e2]; p[e2] = s;
					if (fless(t, a[e1])) { a[e2] = a[e1]; a[e1] = t;
										  p[e2] = p[e1]; p[e1] = s; }
				}
			}
		}
		int less  = left;  
		int great = right; 
 
		if (a[e1] != a[e2] && a[e2] != a[e3] && a[e3] != a[e4] && a[e4] != a[e5]) {
			int pivot1 = a[e2];
			int pivot2 = a[e4];
			int ppivot1 = p[e2];
			int ppivot2 = p[e4];
 
			a[e2] = a[left];
			a[e4] = a[right];
			p[e2] = p[left];
			p[e4] = p[right];
 
			++less, -- great;

			assert(pivot1!=NO_VALUE);
			assert(pivot2!=NO_VALUE);
			for (int k = less - 1; ++k <= great; ) {
				int ak = a[k];
				if (ak != NO_VALUE && ak < pivot1) { 
					a[k] = a[less];
					a[less] = ak;
					swap(p[less], p[k]);
					++less;
				} else if (ak > pivot2) { 
					a[k] = a[great];
					a[great] = ak;
					swap(p[great], p[k]);
					--great;
				}
			}
			
			a[left]  = a[less  - 1]; a[less  - 1] = pivot1;
			a[right] = a[great + 1]; a[great + 1] = pivot2;
			p[left]  = p[less  - 1]; p[less  - 1] = ppivot1;
			p[right] = p[great + 1]; p[great + 1] = ppivot2;
			
			hackedSort(a, p, left, less - 2, leftmost);
			hackedSort(a, p, great + 2, right, false);
			
			hackedSort(a, p, less, great, false);
 
		} else { 
			assert(false);
	   }
	}
 
	void randomShuffle(int *a, int left, int right) {
		for (int i = left; i <= right; i++) {
			int j = left + rng(i - left + 1);
			swap(a[i], a[j]);
		}
	}
 
	bool fless(int a, int b) {
		if (a != NO_VALUE && b != NO_VALUE) {
			return a < b;
		}
		if (a == NO_VALUE) {
			return b > MAX_VALUE;
		}
		if (b == NO_VALUE) {
			return a < MIN_VALUE;
		}
		assert(false);
		return false;
	}
 
	bool fgreater(int a, int b) {
		if (a != NO_VALUE && b != NO_VALUE) {
			return a > b;
		}
		if (a == NO_VALUE) {
			return b < MIN_VALUE;
		}
		if (b == NO_VALUE) {
			return a > MAX_VALUE;
		}
		assert(false);
		return false;
	}

	static vector<int> applyPermutation(const vector<int> &a, const vector<int> &p) {
		int n = a.size();
		vector<int> tmp(n);
		for (int i = 0; i < n; i++) {
			tmp[p[i]] = a[i];
		}
		return tmp;
	}
 
   static void checkValues(const vector<int> &a, int min, int max) {
		vector<bool> b(max - min + 1);
		int n = a.size();
		for (int i = 0; i < n; ++ i) {
			if (b[a[i] - min]) {
				abort();
			}
			b[a[i] - min] = true;
		}
	}

public:
	vector<int> generate(int n) {
		MIN_VALUE = 1;
		MAX_VALUE = n;
		vector<int> a(n, NO_VALUE), p(n);
		rep(i, n) p[i] = i;

		hackedSort(&a[0], &p[0], 0, n-1, true);
		checkValues(a, 1, n);
		checkValues(p, 0, n-1);
 
		a = applyPermutation(a, p);

		return a;
	}
};

int main(int argc, char **argv) {
	int n = -1;
	while(1) {
		if(argc == 1) {
			if(!(cin >> n)) break;
		}else {
			n = strtol(argv[1], NULL, 0);
		}
		if(n <= 0) return 1;
		JavaQuicksortKiller killer;
		vi a;
		a = killer.generate(n);
		if(argc > 1) {
			printf("%d %lld %d\n", n, (ll)1e18, 1);
			rep(i, n) {
				if(i != 0) putchar(' ');
				printf("%d", a[i]);
			}
			puts("");
			break;
		}
	}
	return 0;
}

