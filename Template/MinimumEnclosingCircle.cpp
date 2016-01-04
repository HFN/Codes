#include <algorithm>
#include <cstdlib>
#include <complex>
#include <cstdio>
#define X real()
#define Y imag()
#define eps 1e-9
using namespace std;
typedef complex<long double> point;
const int MAX = 100005;
struct circle
{
	point O;
	long double r;
	circle(point _O, long double _r)
	{
		O = _O;
		r = _r;
	}
};
point P[MAX];
long double dist(point A, point B)
{
	return abs(A - B);
}
long double cross(point A, point B)
{
	return (conj(A) * B).Y;
}
long double ccw(point A, point B, point C)
{
	return cross(B - A, C - A);
}
point intersect(point A, point B, point C, point D)
{
	point AB = B - A;
	point AC = C - A;
	point CD = D - C;
	long double alpha = cross(AC, CD) / cross(AB, CD);
	return A + alpha * AB;
}
point rotate(point A, point B, long double theta)
{
	point AB = B - A;
	AB *= point(cos(theta), sin(theta));
	return A + AB;
}
point get_mid(point A, point B)
{
	point AB = B - A;
	return A + 0.5l * AB;
}
circle get_circle(point A, point B)
{
	point O = get_mid(A, B);
	long double r = dist(O, A);
	return circle(O, r);
}
circle get_circle(point A, point B, point C)
{
	point ABM = get_mid(A, B);
	point ABR = rotate(ABM, B, M_PI * 0.5);
	point ACM = get_mid(A, C);
	point ACR = rotate(ACM, C, M_PI * 0.5);
	point O = intersect(ABM, ABR, ACM, ACR);
	long double r = dist(O, A);
	return circle(O, r);
}
bool isin(point p, circle c)
{
	return (dist(p, c.O) < c.r + eps);
}
bool valid(circle c, int n)
{
	if (c.r < -eps)
		return false;
	for (int i = 0; i < n; i++)
		if (!isin(P[i], c))
			return false;
	return true;
}
circle mec2(point p, point q, int n)
{
	circle lc(point(0.0, 0.0), -1.0);
	circle rc(point(0.0, 0.0), -1.0);
	circle mc = get_circle(p, q);
	for (int i = 0; i < n; i++)
		if (ccw(p, q, P[i]) > 0.0)
		{
			circle c = get_circle(p, q, P[i]);
			if (lc.r < -eps || ccw(p, q, lc.O) < ccw(p, q, c.O))
				lc = c;
		}
		else
		{
			circle c = get_circle(p, q, P[i]);
			if (rc.r < -eps || ccw(p, q, rc.O) > ccw(p, q, c.O))
				rc = c;
		}
	circle ans(point(0.0, 0.0), 1e18);
	if (valid(lc, n) && ans.r > lc.r)
		ans = lc;
	if (valid(rc, n) && ans.r > rc.r)
		ans = rc;
	if (valid(mc, n) && ans.r > mc.r)
		ans = mc;
	return ans;
}
circle mec1(point p, int n)
{
	circle cur = get_circle(P[0], p);
	for (int i = 1; i < n; i++)
		if (!isin(P[i], cur))
			cur = mec2(P[i], p, i);
	return cur;
}
circle mec(int n)
{
	circle cur = get_circle(P[0], P[1]);
	for (int i = 2; i < n; i++)
		if (!isin(P[i], cur))
			cur = mec1(P[i], i);
	return cur;
}
int main()
{
	srand(time(NULL));
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);
			P[i] = point(x, y);
		}
		random_shuffle(P, P + n);
		circle ans = mec(n);
		double x = ans.O.X;
		double y = ans.O.Y;
		double r = ans.r;
		printf("%.2f\n%.2f %.2f\n", r, x, y);
	}
	return 0;
}
