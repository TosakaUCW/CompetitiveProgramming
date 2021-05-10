#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;

int n, k, ans;
int rt, f[N], siz[N], dis[N];
bool vis[N];

int hd[N], E;
struct Edge { int ne, to, dis; } e[N << 1];
void add(int u, int v, int dis) { e[++E] = {hd[u], v, dis}, hd[u] = E; }
#define fore(i, u, v) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

int tot, a[N];

void getrt(int u, int fa, int sum)
{
	siz[u] = 1, f[u] = 0;
	fore(i, u, v) if (v != fa and !vis[v])
		getrt(v, u, sum), siz[u] += siz[v], f[u] = std::max(f[u], siz[v]);
	f[u] = std::max(f[u], sum - siz[u]);
	if (f[rt] > f[u] or !rt) rt = u;
}

void getdis(int u, int fa)
{
	a[++tot] = dis[u];
	fore(i, u, v) if (!vis[v] and v != fa) dis[v] = dis[u] + e[i].dis, getdis(v, u);
}

int calc(int u, int dis)
{
	int res = 0;
	::dis[u] = dis, tot = 0, getdis(u, 0);
	std::sort(a + 1, a + 1 + tot);
	for (int L = 1, R = tot; L <= R;)
		if (a[L] + a[R] <= k) res += R - L, L++;
		else R--;
	return res;
}

void solve(int u)
{
	vis[u] = 1, ans += calc(u, 0);
	fore(i, u, v) if (!vis[v]) ans -= calc(v, e[i].dis), rt = 0, getrt(v, 0, siz[v]), solve(rt);
}

signed main()
{
	n = read();
	for (int i = 1, u, v, dis; i < n; i++)
		u = read(), v = read(), dis = read(), add(u, v, dis), add(v, u, dis);
	k = read(), f[rt = 0] = n, getrt(1, 0, n), solve(rt);
	return printf("%lld", ans), 0;
}
