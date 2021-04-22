#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>

#define int long long
#define cnt (idx[0])

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = 5e4 + 5;
const int P = 998244353;

int n, m, k;
int f[2][N], idx[N];
std::map<int, int> map;
struct Node { int x, y; } edge[M];

signed main()
{
	n = read(), m = read(), k = read();
	map[1] = idx[++cnt] = f[0][1] = 1;
	for (int i = 1, x, y; i <= k; i++)
	{
		x = read(), y = read();
		if (!map.count(x)) map[x] = ++cnt;
		if (!map.count(y)) map[y] = ++cnt;
		edge[i] = {map[x], map[y]};
	}
	int cur = 0;
	for (int sum = 1, last; m--; cur ^= 1)
	{
		last = sum, sum = last * (n - 1) % P;
		for (int i = 1; i <= cnt; i++)
			f[cur ^ 1][i] = (last - f[cur][i] + P) % P;
		for (int i = 1, x, y; i <= k; i++)
			if ((x = edge[i].x) != (y = edge[i].y))
				f[cur ^ 1][y] = (f[cur ^ 1][y] - f[cur][x] + P) % P,
				sum = (sum - f[cur][x] + P) % P;
	}
	return printf("%lld", f[cur][1]), 0;
}
