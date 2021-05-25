#include <stdio.h>
#include <algorithm>
#include <vector>

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N =  1e5 + 5;

int n;
std::vector<int> g[N];
struct Node { int a, b, c, d; };
std::vector<Node> ans;

#define pb emplace_back

int dfs(int u, int fa)
{
	int cnt = 0, nxt = u;
	for (auto v : g[u])
		if (v ^ fa)
		{
			int to = dfs(v, u);
			if (to)
			{
				++cnt;
				if (cnt == 1) nxt = to;
				else if (cnt == 2) ans.pb({fa, u, nxt, to}), nxt = -1;
				else ans.pb({u, v, v, to});
			}
		}
	return nxt;
}

void solve()
{
	n = read(), ans.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1, u, v; i < n; i++)
		u = read(), v = read(), g[u].pb(v), g[v].pb(u);
	for (int i = 1; i <= n; i++)
		if (g[i].size() == 1) { rt = dfs(i, i); break; }
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d %d %d %d\n", x.a, x.b, rt, x.c), rt = x.d;
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
