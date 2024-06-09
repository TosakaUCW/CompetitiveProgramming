#include <stdio.h>
#include <memory.h>
#include <algorithm>

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N = 2e5 + 5;
const int K = 1e6 + 5;
const int INF = 0x7f7f7f7f;

int n, k, ans = INF;

int hd[N], E;
struct Node { int ne, to, dis; } e[N << 1];
void add(int u, int v, int dis) { e[++E] = {hd[u], v, dis}, hd[u] = E; }
#define edge(i, u, v) for(int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

#define pii std::pair<int, int>
#define fi first
#define se second
int rt, f[N], siz[N], min[K];
int atot;
pii a[N];
bool vis[N];

int sum;
void getrt(int u, int fa)
{
	siz[u] = 1, f[u] = 0;
	edge(i, u, v) if (!vis[v] and v ^ fa)
		getrt(v, u), siz[u] += siz[v], f[u] = std::max(f[u], siz[v]);
	f[u] = std::max(f[u], sum - siz[u]);
	if (f[rt] > f[u] or !rt) rt = u;
}

void getdis(int u, int fa, int dist, int tot)
{
	if (dist > k) return;
	a[++atot] = {dist, tot};
	edge(i, u, v) if (v ^ fa and !vis[v])
		getdis(v, u, dist + e[i].dis, tot + 1);
}

void solve(int u)
{
	vis[u] = 1, min[0] = 0, atot = 0;
	edge(i, u, v) if (!vis[v])
	{
		int last = atot;
		getdis(v, u, e[i].dis, 1);
		for (int j = last + 1; j <= atot; j++) 
			ans = std::min(ans, min[k - a[j].fi] + a[j].se);
		for (int j = last + 1; j <= atot; j++)
			min[a[j].fi] = std::min(min[a[j].fi], a[j].se);
	}
	for (int i = 1; i <= atot; i++) min[a[i].fi] = INF;
	edge(i, u, v) if (!vis[v]) rt = 0, sum = siz[v], getrt(v, 0), solve(rt);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4149_6.in", "r", stdin);
	freopen("ans.out", "w", stdout);
#endif
	n = read(), k = read();
	for (int i = 1, u, v, dis; i < n; i++)
		u = read() + 1, v = read() + 1, dis = read(), add(u, v, dis), add(v, u, dis);
	memset(min, 0x7f, sizeof min);
	f[rt = 0] = sum = n, getrt(1, 0), solve(rt);
	return printf("%d", ans == INF ? -1 : ans), 0;
}
