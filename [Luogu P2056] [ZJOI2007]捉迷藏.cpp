#include <stdio.h>
#include <algorithm>
#include <queue>

int read(int x = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return x;
}

const int N = 5e5 + 5;
const int INF = 2147483647;

int n;
bool col[N], vis[N];

int hd[N], E;
struct Edge { int ne, to; } e[N << 1];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }
#define edge(i, u, v) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

int sum, rt, siz[N], f[N], fa[N];

struct Graph
{
	int dep[N], fa[N], son[N], siz[N], top[N];
	void init() { dfs1(1, 0), dfs2(1); }
	void dfs1(int u, int fath)
	{
		siz[u] = 1, dep[u] = dep[fath] + 1, fa[u] = fath;
		edge(i, u, v) if (v != fath) dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u]; 
	}
	void dfs2(int u)
	{
		top[u] = u == son[fa[u]] ? top[fa[u]] : u;
		if (son[u]) dfs2(son[u]);
		edge(i, u, v) if (v != fa[u] and v != son[u]) dfs2(v);
	}
	int LCA(int x, int y)
	{
		for (; top[x] != top[y]; x = fa[top[x]])
			if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		return dep[x] < dep[y] ? x : y;
	}
	int DIS(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
} G;

struct Heap
{
	std::priority_queue<int> a, b;
	int size() { return a.size() - b.size(); }
	void update() { while (!b.empty() and !a.empty() and a.top() == b.top()) a.pop(), b.pop(); }
	int top() { return update(), a.top(); }
	void pop() { update(), a.pop(); }
	void ins(int x) { a.push(x); }
	void del(int x) { b.push(x); }
	int top2() { int x, y; x = top(), pop(), y = top(), ins(x); return y;  }
} ans, B[N], A[N];

void ans_ins(Heap &x) { if (x.size() >= 2) ans.ins(x.top() + x.top2()); }
void ans_del(Heap &x) { if (x.size() >= 2) ans.del(x.top() + x.top2()); }

void getrt(int u, int fa)
{
	siz[u] = 1, f[u] = 0;
	edge(i, u, v) if (!vis[v] and v != fa) getrt(v, u), siz[u] += siz[v], f[u] = std::max(f[u], siz[v]);
	f[u] = std::max(f[u], sum - siz[u]);
	if (f[u] < f[rt]) rt = u;
}
void getdis(int u, int fa, int dep, Heap &A)
{
	A.ins(dep);
	edge(i, u, v) if (!vis[v] and v != fa) getdis(v, u, dep + 1, A);
}
void solve(int u)
{
	vis[u] = 1;
	edge(i, u, v) if (!vis[v]) 
		rt = 0, sum = siz[v], f[rt] = INF, getrt(v, u), 
		fa[rt] = u, getdis(v, u, 1, A[rt]), B[u].ins(A[rt].top()),
		solve(rt);
	B[u].ins(0), ans_ins(B[u]);
}
void modify(int u, bool col)
{
	ans_del(B[u]);
	col ? B[u].del(0) : B[u].ins(0);
	ans_ins(B[u]);
	for (int x = u; fa[x]; x = fa[x])
	{
		int y = fa[x], dis = G.DIS(u, y);
		ans_del(B[y]);
		if (A[x].size()) B[y].del(A[x].top());
		col ? A[x].del(dis) : A[x].ins(dis);
		if (A[x].size()) B[y].ins(A[x].top());
		ans_ins(B[y]);
	}
}

int main()
{
	n = read();
	for (int i = 1, u, v; i < n; i++) 
		u = read(), v = read(), add(u, v), add(v, u);
	G.init(), f[rt = 0] = INF, sum = n, getrt(1, 0), solve(rt);
	for (int q = read(), cnt = n; q--; )
	{
		char opt;
        scanf("%s", &opt);
		if (opt == 'G')
			if (cnt >= 2) printf("%d\n", ans.top());
			else puts(cnt ? "0" : "-1");
		else 
		{
			int x = read();
			if (col[x]) ++cnt;
			else --cnt;
			modify(x, col[x] ^= 1);
		}
	}
	return 0;
}
