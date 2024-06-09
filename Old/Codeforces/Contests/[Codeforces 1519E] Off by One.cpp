#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

#define int long long
#define pii std::pair<int, int>
#define mkp std::make_pair
#define fi first
#define se second
#define gcd std::__gcd
#define pb push_back

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;

int n, m, tot;
int head[N], E, match[N];
bool matched[N], vis[N];
std::map<pii, int> map;
std::vector<pii> ans;
struct Node { int next, to; } e[N << 3];
void add(int u, int v) { e[E] = {head[u], v}, head[u] = E++; }

void dfs(int u)
{
	vis[u] = 1;
	for (int i = head[u], v, idx; i; i = e[i].next)
	{
		v = e[i].to, idx = i / 2 + 1, e[i].to = e[i ^ 1].to = 0;
		if (v)
		{
			if (!vis[v]) dfs(v);
			if (match[v])
				ans.pb(mkp(idx, match[v])), match[v] = 0;
			else if (match[u])
				ans.pb(mkp(idx, match[u])), match[u] = 0;
			else
				match[u] = idx;
		}
	}
}

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int a = read(), b = read(), c = read(), d = read();
		int x1 = (a + b) * d, y1 = b * c;
		int x2 = a * d, y2 = b * (c + d);
		int g1 = gcd(x1, y1), g2 = gcd(x2, y2);
		x1 /= g1, y1 /= g1, x2 /= g2, y2 /= g2;
		pii u = mkp(x1, y1), v = mkp(x2, y2);
		if (map.find(u) == map.end())
			map[u] = ++tot;
		if (map.find(v) == map.end())
			map[v] = ++tot;
		add(map[u], map[v]), add(map[v], map[u]);
	}
	for (int i = 1; i <= tot; i++) if (!vis[i]) dfs(i);
	printf("%d\n", ans.size());
	for (pii x : ans) printf("%lld %lld\n", x.fi, x.se); 
	return 0;
}
