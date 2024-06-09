#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

using std::min;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 600 + 5;

int n, m;
int dis[N], d[N], vis[N];

int hd[N], E;
struct Node { int ne, to, w; } e[N * N];
void add(int u, int v, int w) { e[++E] = {hd[u], v, w}, hd[u] = E; }
#define fore(u) for (int i = hd[u], v = e[i].to, w = e[i].w; i; i = e[i].ne, v = e[i].to, w = e[i].w)

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis), memset(vis, 0, sizeof vis);
	fore(s) dis[v] = w;
	for (int T = 1; T < n; T++)
	{
		int u = 0;
		for (int i = 1; i <= n; i++) 
			if (!vis[i] and (!u or dis[i] <= dis[u])) u = i;
        #define g(x) ((x - 1) % n + 1)
		vis[u] = 1, dis[g(u + 1)] = min(dis[u] + 1, dis[g(u + 1)]);
        fore(u) v = g(v + dis[u]), dis[v] = min(dis[u] + w, dis[v]);
	}
	for (int i = 1; i <= n; i++) printf("%d ", i == s ? 0 : dis[i]);
	puts("");
}

int main()
{
	n = read(), m = read();
	for (int i = 1, u, v, dis; i <= m; i++)
		u = read() + 1, v = read() + 1, dis = read(), add(u, v, dis);
    for (int i = 1; i <= n; i++) dijkstra(i);
	return 0;
}
