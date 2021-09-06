#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;
const int M = 1e6 + 5;

int n, m, k, f[N], L, R, ans;
struct Node { int u, v, d; } e[M];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int judge(int x)
{
	int tot = 0;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++)
		if (e[i].d <= x)
		{
			int fx = find(e[i].u), fy = find(e[i].v);
			if (fx ^ fy) f[fy] = fx;
		}
	for (int i = 1; i <= n; i++) if (f[i] == i) tot++;
	return tot;
}

void solve()
{
	n = read(), m = read(), k = read(), L = 0, R = 1e9 + 7, ans = -1;
	for (int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].d = read();
	for (int mid; L <= R; )
		if (judge(mid = L + R >> 1) < k) R = mid - 1;
		else if (judge(mid = L + R >> 1) == k) ans = mid, R = mid - 1;
		else L = mid + 1;
	printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

