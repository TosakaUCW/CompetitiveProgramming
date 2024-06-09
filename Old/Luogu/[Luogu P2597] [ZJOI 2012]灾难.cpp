#include <stdio.h>
#include <algorithm>
#include <queue>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e6 + 5;
const int M = 2e6 + 5;

int n, ans[N], ind[N], rk[N];
int head[N], E, f[N][20], fa[N], dep[N]{-1};
struct Node { int next, to; } e[M];
void add(int u, int v) { e[++E] = {head[u], v}, head[u] = E; }

std::queue<int> Q;

void topo_sort()
{
	Q.push(n + 1);
	for (int u; !Q.empty();)
	{
		rk[++rk[0]] = u = Q.front(), Q.pop();
		for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)
			if (!--ind[v]) Q.push(v);
	}
}

void init(int p, int fa)
{
	dep[p] = dep[fa] + 1, f[p][0] = fa;
	for (int i = 1; i <= 18; i++) f[p][i] = f[f[p][i - 1]][i - 1];
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 18; ~i; i--) if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = 18; ~i; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
		
}

int main()
{
	n = read();
	for (int i = 1, x; i <= n; i++)
	{
		while (x = read()) add(x, i), ++ind[i];
		if (!ind[i]) ++ind[i], add(n + 1, i);
	}
	topo_sort();
	for (int i = 1, u; i <= rk[0]; i++)
	{
		if (fa[u = rk[i]]) init(u, fa[u]);
		for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)
			fa[v] = fa[v] ? lca(fa[v], u) : u;
	}
	for (int i = n + 1, u; i >= 2; i--) ans[f[u = rk[i]][0]] += ans[u] + 1;
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
