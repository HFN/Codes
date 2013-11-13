// SGU 275 To xor or not to xor
#include <iostream>
using namespace std;
const int MAX = 105;
bool mat[64][MAX], mat2[64][MAX], res[64], ans[64];
int n;
bool solve(int k)
{
	for (int i = 0; i < 64; i++)
		for (int j = 0; j < MAX; j++)
			mat[i][j] = mat2[i][j];
	for (int i = 0; i < 64; i++)
		res[i] = ans[i];
	int i, j;
	for (i = j = 0; i <= k && j < n; i++, j++)
	{
		if (mat[i][j] == 0)
		{
			for (int x = i + 1; x <= k; x++)
				if (mat[x][j])
				{
					for (int y = j; y < n; y++)
						swap(mat[i][y], mat[x][y]);
					swap(res[i], res[x]);
					break;
				}
			if (mat[i][j] == 0)
			{
				i--;
				continue;
			}
		}
		for (int x = i + 1; x <= k; x++)
			if (mat[x][j])
			{
				for (int y = j; y < n; y++)
					mat[x][y] ^= mat[i][y];
				res[x] ^= res[i];
			}
	}
	for (int x = i; x <= k; x++)
		if (res[x])
			return false;
    return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long val;
		cin >> val;
		for (int j = 63; j >= 0; j--, val >>= 1)
			mat2[j][i] = val & 1;
	}
	for (int i = 0; i < 64; i++)
	{
		ans[i] = 1;
		if (!solve(i))
			ans[i] = 0;
	}
	long long answer = 0;
	for (int i = 0; i < 64; i++)
		answer = answer * 2 + ans[i];
	cout << answer;
	return 0;
}
