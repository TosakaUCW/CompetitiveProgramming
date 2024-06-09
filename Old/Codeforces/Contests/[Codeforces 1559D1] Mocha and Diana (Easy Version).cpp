#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e3 + 5;

int n, m[2], f[2][N];
std::vector< std::pair<int, int> > ans;

int find(int i, int x) { return x == f[i][x] ? x : f[i][x] = find(i, f[i][x]); }

int main()
{
	n = read(), m[0] = read(), m[1] = read();
	for (int i = 1; i <= n; i++) f[0][i] = f[1][i] = i;
	for (int i = 0; i < 2; i++) for (int j = 1, u, v; j <= m[i]; j++)
	{
		int x = find(i, read()), y = find(i, read());
		if (x ^ y) f[i][x] = y;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int a = find(0, i), b = find(0, j);
			int c = find(1, i), d = find(1, j);
			if (a ^ b and c ^ d) ans.push_back({i, j}), f[0][a] = b, f[1][c] = d;
		}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
