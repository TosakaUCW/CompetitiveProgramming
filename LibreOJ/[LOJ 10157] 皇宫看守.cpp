#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n;
int head[N], num_edge;
int f[N][3];

struct Node
{
	int next, to;
} edge[2 * N];

void add_edge(int u, int v)
{
	edge[++num_edge].next = head[u];
	edge[num_edge].to = v;
	head[u] = num_edge;
}

void dfs(int u, int fa)
{
	int d = INF;
	for (int i = head[u]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs(v, u);
		f[u][0] += std::min(f[v][1], f[v][2]);
		f[u][1] += std::min(f[v][1], f[v][2]);
		f[u][2] += std::min(f[v][0], std::min(f[v][1], f[v][2]));
		d = std::min(d, f[v][2] - std::min(f[v][1], f[v][2]));
	}
	f[u][1] += d;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int u, k, m;
		scanf("%d%d%d", &u, &k, &m);
		f[u][2] = k;
		for (int j = 1; j <= m; j++)
		{
			int v;
			scanf("%d", &v);
			add_edge(u, v), add_edge(v, u);
		}
	}
	dfs(1, 0);
	printf("%d", std::min(f[1][1], f[1][2]));
	return 0;
}
