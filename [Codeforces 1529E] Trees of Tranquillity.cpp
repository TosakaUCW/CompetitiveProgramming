#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 3e5 + 5;

int n, timer, ans, st[N], ed[N];
std::set<std::pair<int, int>> S;
std::vector<int> g1[N], g2[N];

#define pb push_back

void dfs1(int u)
{
	st[u] = ++timer;
	for (int v : g2[u]) dfs1(v);
	ed[u] = timer;
}

int go(int u)
{
	auto it = S.lower_bound({st[u], u});
	if (it != S.end() and ed[it -> second] <= ed[u]) return -1;
	if (it == S.begin()) return 0;
	--it;
	int anc = it -> second;
	if (ed[anc] >= ed[u]) return S.erase(it), anc;
	return 0;
}

void dfs2(int u)
{
	int opt = go(u);
	if (opt != -1) S.insert({st[u], u});
	ans = std::max(ans, int(S.size()));
	for (int v : g1[u]) dfs2(v);
	if(opt != -1)
	{
		S.erase({st[u], u});
		if (opt != 0) S.insert({st[opt], opt});
	}
}

void solve()
{
	n = read(), timer = ans = 0, S.clear();
	for (int i = 1; i <= n; i++) g1[i].clear(), g2[i].clear();
	for (int i = 2; i <= n; i++) g1[read()].pb(i);
	for (int i = 2; i <= n; i++) g2[read()].pb(i);
	dfs1(1), dfs2(1), printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
