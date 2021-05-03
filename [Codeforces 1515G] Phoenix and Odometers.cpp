#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define int long long
#define pb push_back
using std::__gcd;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;

int n, m;
bool vis[N];
std::stack<int> S;
std::vector<int> V[N];
int dis[N], g[N], gcd;
int E, C, head[N], dfn[N], low[N], col[N];
struct Node { int next, to, dis; } e[N];

void add(int u, int v, int dis) { e[++E] = {head[u], v, dis}, head[u] = E; }

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfn[0], S.push(u), vis[u] = 1;
	for (int i = head[u], v; i; i = e[i].next)
		if (!dfn[v = e[i].to]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (vis[v]) low[u] = std::min(low[u], dfn[v]);
	if (dfn[u] == low[u])
	{
		V[col[u] = ++C].pb(u), vis[u] = 0;
		for (int x; S.top() != u; S.pop()) col[x = S.top()] = C, vis[x] = 0, V[C].pb(x);
		S.pop();
	}
}

void dfs(int u)
{
	vis[u] = true;
	for (int i = head[u], v; i; i = e[i].next)
		if (col[u] == col[v = e[i].to])
			if (!vis[v]) dis[v] = dis[u] + e[i].dis, dfs(v);
			else gcd = __gcd(gcd, dis[u] + e[i].dis - dis[v]);
}

signed main()
{
	n = read(), m = read();
	for (int i = 1, u, v; i <= m; i++) u = read(), v = read(), add(u, v, read());
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= C; i++) gcd = 0, dfs(V[i][0]), g[i] = gcd;
	for (int q = read(), u, s, t; q--; )
	{
		u = read(), s = read(), t = read();
		if (!s) puts("YES");
		else if ((t - s) % __gcd(g[col[u]], t)) puts("NO");
		else puts("YES");
	}
	return 0;
}
