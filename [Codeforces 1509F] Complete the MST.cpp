#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch -48, ch = getchar();
	return f ? -x : x;
}

#define ins insert

const int N = 2e5 + 5;
const int INF = 2147483647;

int n, m, sum, min = INF;
long long ans, K;
std::queue<int> Q;
std::set<int> S, G[N];
bool vis[N], col[N];

struct Edge
{
	int u, v, dis;
	bool friend operator < (Edge a, Edge b) { return a.dis < b.dis; }
	void init() 
	{ 
		u = read(), v = read(), dis = read();
		G[u].ins(v), G[v].ins(u), sum ^= dis;
	}
} e[N << 1];
struct DSU
{
	int fa[N];
	int find(int x) { return x == fa[x] ? x : x = find(fa[x]); }
} dsu;

void presolve()
{
#define sit std::set<int>::iterator
#define make(x, y) vis[x] = true, Q.push(x), S.erase(x), dsu.fa[x] = y
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			make(i, i);
			for (int u, v; !Q.empty(); )
			{
				u = Q.front(), Q.pop();
				for (sit it = S.begin(); it != S.end(); )
					if (!G[u].count(v = *it++))
						make(v, u), K--;
			}
		}
#undef sit
#undef make(x, y)
}

int main()
{
	n = read(), m = read(), K = 1LL * n * (n - 1) / 2 - m;
	for (int i = 1; i <= n; i++) S.ins(i);
	for (int i = 1; i <= m; i++) e[i].init();
	std::sort(e + 1, e + 1 + m);
	presolve();
	for (int i = 1; i <= m; i++)
	{
		int fx = dsu.find(e[i].u), fy = dsu.find(e[i].v);
		if (fx != fy)
			dsu.fa[fx] = fy, ans += e[i].dis, col[i] = 1;
	}
	if (K > 0) return printf("%lld", ans), 0;
	for (int i = 1; i <= n; i++) dsu.fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int fx = dsu.find(e[i].u), fy = dsu.find(e[i].v);
		if (fx != fy)
		{
			dsu.fa[fx] = fy;
			if (!col[i]) { min = e[i].dis; break; }
		}
	}
	return printf("%lld", ans + std::min(min, sum)), 0;
}
