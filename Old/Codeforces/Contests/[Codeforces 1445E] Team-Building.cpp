#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using std::swap;
#define int long long
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m, k, ans, cnt;
int a[N], b[N];
bool odd[N];
int col[N], tot;
std::map<pii, int> map;
std::vector<int> G[N];

struct UFS
{
	struct Stack { int x, y, rk; } st[N];
	int fa[N], rk[N], top;
	void init() { for (int i = 1; i <= n * 2; i++) fa[i] = i; }
	int find(int x) { return x == fa[x] ? x : find(fa[x]); }
	bool merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if (fx == fy) return false;
		if (rk[fx] > rk[fy]) swap(x, y), swap(fx, fy);
		st[++top] = {fx, fy, rk[fy]};
		fa[fx] = fy, rk[fy] += rk[fx] == rk[fy];
		return true;
	}
	void undo(int k) 
	{
		while (k--)
		{
			Stack &now = st[top--];
			int x = now.x, y = now.y, rank = now.rk;
			fa[x] = x, rk[y] = rank;
		}
	}
} U;

signed main()
{
	n = read(), m = read(), k = read(), U.init();
	for (int i = 1; i <= n; i++) col[i] = read();
	for (int i = 1, fx, fy; i <= m; i++)
		if (col[a[i] = read()] == col[b[i] = read()])
			if ((fx = U.find(a[i])) == (fy = U.find(b[i]))) odd[col[a[i]]] = true;
			else U.merge(a[i], b[i] + n), U.merge(a[i] + n, b[i]);
	for (int i = 1; i <= m; i++)
		if (col[a[i]] != col[b[i]] and !odd[col[a[i]]] and !odd[col[b[i]]])
		{
			int x = col[a[i]], y = col[b[i]];
			if (x > y) swap(x, y);
			if (!map.count({x, y})) map[{x, y}] = ++tot;
			G[map[{x, y}]].pb(i);
		}
	for (auto i : map)
	{
		int top = U.top, idx = i.se;
		for (auto j : G[idx])
		{
			int x = a[j], y = b[j];
			int fx = U.find(x), fy = U.find(y);
			if (fx == fy) { ans--; break; }
			else U.merge(x, y + n), U.merge(x + n, y);
		}
		U.undo(U.top - top);
	}
	for (int i = 1; i <= k; i++) cnt += !odd[i];
	return printf("%lld", cnt * (cnt - 1) / 2 + ans), 0;
}
