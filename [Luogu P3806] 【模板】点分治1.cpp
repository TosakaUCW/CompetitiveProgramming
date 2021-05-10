#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;
const int INF = 2147483647;

int n, m, q[N];
int rt, max[N], siz[N];
bool vis[N], ok[N];

int head[N], E;
struct Edge { int next, to, dis; } e[N];

int a_tot;
struct Node
{
	int cur, dis, bel;
	bool friend operator < (Node a, Node b) { return a.dis < b.dis; }
} a[N];


void add(int u, int v, int dis) { e[++E] = {head[u], v, dis}, head[u] = E; }

#define fore(i, u, v) for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)

void getrt(int u, int fa, int tot)
{
	siz[u] = 1, max[u] = 0;
	fore(i, u, v) if (v != fa and !vis[v]) 
		getrt(v, u, tot), siz[u] += siz[v], max[u] = std::max(max[u], siz[v]);
	max[u] = std::max(max[u], tot - siz[u]);
	if (max[rt] > max[u] or !rt) rt = u;
}

void get_dis(int u, int fa, int dis, int bel)
{
    a[++a_tot] = {u, dis, bel};
    fore(i, u, v) if (!vis[v] and v != fa) get_dis(v, u, dis + e[i].dis, bel); 
}

void calc(int u)
{
	a[a_tot = 1] = {u, 0, u};
	fore(i, u, v) if (!vis[v]) get_dis(v, u, e[i].dis, v);
	std::sort(a + 1, a + 1 + a_tot);
	for (int i = 1; i <= m; i++)
		if (!ok[i])
			for (int L = 1, R = a_tot; L < R; )
				if (a[L].dis + a[R].dis > q[i]) R--;
				else if (a[L].dis + a[R].dis < q[i]) L++;
				else if (a[L].bel == a[R].bel)
                {
					if (a[R].dis == a[R - 1].dis) R--;
					else L++;
                }
				else { ok[i] = 1; break; }
}

void solve(int u)
{
	vis[u] = 1, calc(u);
	fore(i, u, v) if (!vis[v]) rt = 0, getrt(v, 0, siz[v]), solve(rt);
}

int main()
{
	n = read(), m = read();
	for (int i = 1, u, v, dis; i < n; i++) u = read(), v = read(), dis = read(), add(u, v, dis), add(v, u, dis);
	for (int i = 1; i <= m; i++) 
	{
		q[i] = read();
		if (!q[i]) ok[i] = true;
	}
	max[rt = 0] = n, getrt(1, 0, n), solve(rt);
	for (int i = 1; i <= m; i++) puts(ok[i] ? "AYE" : "NAY");
	return 0;
}
