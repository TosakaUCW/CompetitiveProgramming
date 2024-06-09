#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 4e5 + 5;

int n, m, k;
int stk[N];
bool vis[N];
int st[N], spd[N], ask[N], colid[N];
int hd[N], E, dep[N], siz[N], dfn[N], idx[N], fa[N], son[N], top[N];
std::vector<int> g[N], S;
struct Edge { int ne, to; } e[N << 1];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }
#define fore(u) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)
#define pb push_back
#define addg(u, v) g[u].pb(v), g[v].pb(u)

void dfs1(int u, int fa)
{
	siz[u] = 1, dep[u] = dep[fa] + 1, ::fa[u] = fa;
	fore(u) if (v ^ fa) dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}

void dfs2(int u)
{
	dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
	if (son[u]) dfs2(son[u]);
	fore(u) if (v ^ fa[u] and v ^ son[u]) dfs2(v);
}

void dfs3(int u, int fa)
{
	S.pb(u);
	for (int v : g[u]) if (v ^ fa) dfs3(v, u);
}

int LCA(int x, int y)
{
	for (; top[x] ^ top[y]; x = fa[top[x]]) if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
	return dep[x] < dep[y] ? x : y;
}

void init()
{
	std::sort(S.begin(), S.end(), [](int x, int y) { return dfn[x] < dfn[y]; });
	S.erase(std::unique(S.begin(), S.end()), S.end());
	int top = 1;
	stk[1] = 1;
	for (int x : S)
		if (x ^ 1)
		{
			int lca = LCA(x, stk[top]);
			if (lca ^ stk[top])
			{
				while (top > 1 and dfn[stk[top - 1]] >= dfn[lca])
					addg(stk[top - 1], stk[top]), top--;
				if (stk[top] ^ lca) addg(lca, stk[top]), stk[top] = lca;
			}
			stk[++top] = x;
		}
	for (int i = 1; i < top; i++) addg(stk[i], stk[i + 1]);
}

struct Node
{
	int dis, tim, pre, idx;
//	bool friend operator < (Node a, Node b) { return a.tim == b.tim ? colid[a.pre] < colid[b.pre] : a.tim < b.tim; }
	bool operator < (const Node a) const { return a.tim == tim ? colid[a.pre] < colid[pre] : a.tim < tim; }
} dis[N];

int get(int dist, int pre) { return (dist - 1) / spd[pre] + 1; }

void dijk()
{
	std::priority_queue<Node> Q;
	S.clear(), dfs3(1, 0);
	for (int i = 0; i < int(S.size()); i++) dis[S[i]] = {n + 1, n + 1, 0, S[i]}, vis[S[i]] = 0;
	for (int i = 1; i <= m; i++)
		dis[st[i]].dis = dis[st[i]].tim = 0, dis[st[i]].pre = st[i], Q.push(dis[st[i]]);
	for (int u; !Q.empty(); )
	{
		u = Q.top().idx, Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : g[u])
		{
			Node y;
			int dist = dis[u].dis + abs(dep[u] - dep[v]);
			y = {dist, get(dist, dis[u].pre), dis[u].pre, v};
			if (!(y < dis[v])) dis[v] = y, Q.push(y);
		}
	}
}

int main()
{
	n = read();
	for (int i = 1, u, v; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
	dfs1(1, 0), dfs2(1);
	for (int q = read(); q--; )
	{
		m = read(), k = read(), S.clear();
		for (int i = 1; i <= m; i++) st[i] = read(), colid[st[i]] = i, spd[st[i]] = read(), S.pb(st[i]);
		for (int i = 1; i <= k; i++) ask[i] = read(), S.pb(ask[i]);
		init(), dijk();
		for (int i = 1; i <= k; i++) printf("%d ", colid[dis[ask[i]].pre]);
		for (int x : S) g[x].clear();
		puts("");
	}
	return 0;
}
