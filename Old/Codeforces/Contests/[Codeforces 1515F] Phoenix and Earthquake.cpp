#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 3e5 + 5;
const int M = N << 1;

int n, m, x, L, R;
int a[N], ans[N];
bool vis[N];
int head[N], num_edge;
struct Node { int next, to; } edge[M];
void add_edge(int u, int v) { edge[++num_edge] = {head[u], v}, head[u] = num_edge; }

void dfs(int u)
{
	vis[u] = true;
	for (int i = head[u], v; i; i = edge[i].next)
		if (!vis[v = edge[i].to])
		{
			dfs(v);
			if (a[u] + a[v] >= x)
				a[u] = a[u] + a[v] - x, ans[L++] = i + 1 >> 1;
			else 
				ans[R--] = i + 1 >> 1;
		}
}

signed main()
{
	n = read(), m = read(), x = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (std::accumulate(a + 1, a + 1 + n, 0LL) < (n - 1) * x) return puts("NO"), 0;
	for (int i = 1, u, v; i <= m; i++)
		u = read(), v = read(), add_edge(u, v), add_edge(v, u);
	L = 1, R = n - 1, dfs(1), puts("YES");
	for (int i = 1; i < n; i++) printf("%lld\n", ans[i]);
	return 0;
}
