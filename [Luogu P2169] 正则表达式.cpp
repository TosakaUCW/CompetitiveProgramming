#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <queue>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, m;
int hd[N], E;
int u[N], v[N], di[N];
struct Node { int ne, to, dis; } e[M];
void add(int u, int v, int dis) { e[++E] = {hd[u], v, dis}, hd[u] = E; }
#define fore(u) for (int i = hd[u], v = e[i].to; i; i = e[i].ne, v = e[i].to)

int dfn[N], low[N], timer;
std::stack<int> S;
int num_scc, bel[N];
bool inStack[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer, S.push(u), inStack[u] = true;
    fore (u)
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], low[v]);
    if (low[u] == dfn[u])
    {
        ++num_scc;
        int x;
        do { x = S.top(), bel[x] = num_scc, inStack[x] = false, S.pop(); } while (x != u);
    }
}

int dis[N];
bool vis[N];
struct node
{
    int cur, dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};
std::priority_queue<node> Q;

void dijkstra(int s = bel[1])
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0, Q.push(node{s, 0});
    for (int u; !Q.empty(); )
    {
        u = Q.top().cur, Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        fore (u)
            if (dis[v] > dis[u] + e[i].dis)
                dis[v] = dis[u] + e[i].dis, Q.push(node{v, dis[v]});
    }
}

int main()
{
	freopen("regexp16.in", "r", stdin);
	freopen("regexp.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; i++) u[i] = read(), v[i] = read(), di[i] = read(), add(u[i], v[i], di[i]);
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	memset(hd, 0, sizeof hd), memset(e, 0, sizeof e), E = 0;
	for (int i = 1; i <= m; i++) if (bel[u[i]] != bel[v[i]]) add(bel[u[i]], bel[v[i]], di[i]);
	return dijkstra(), printf("%d", dis[bel[n]]), 0;
}

