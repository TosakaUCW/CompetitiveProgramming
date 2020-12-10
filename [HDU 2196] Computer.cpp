#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;

int n;
int head[N], num_edge;
int u[N];
int d1[N], d2[N], c1[N], c2[N];

struct Node
{
	int next, to, dis;
} edge[2 * N];

void add_edge(int u, int v, int dis)
{
	edge[++num_edge].next = head[u];
	edge[num_edge].to = v;
	edge[num_edge].dis = dis;
	head[u] = num_edge;
}

void dfs1(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		int dis = edge[i].dis;
		if (v == fa)
			continue;
		dfs1(v, u);
		if (d1[u] <= d1[v] + dis)
		{
			d2[u] = d1[u];
			d1[u] = d1[v] + dis;
			c1[u] = v;
		}
		else if (d2[u] < d1[v] + dis)
		{
			d2[u] = d1[v] + dis;
			c2[u] = v;
		}
	}
}

void dfs2(int cur, int fa)
{

	for (int i = head[cur]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		int dis = edge[i].dis;
		if (v == fa)
			continue;
		if (c1[cur] != v)
			u[v] = std::max(u[cur], d1[cur]) + dis;
		else
			u[v] = std::max(u[cur], d2[cur]) + dis;
		dfs2(v, cur);
	}
}

int main()
{
	while (~scanf("%d", &n))
	{
		num_edge = 0;
		memset(d1, 0, sizeof d1);
		memset(d2, 0, sizeof d2);
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);
		memset(u, 0, sizeof u);
		memset(head, 0, sizeof head);
		for (int i = 2; i <= n; i++)
		{
			int v, dis;
			scanf("%d%d", &v, &dis);
			add_edge(i, v, dis), add_edge(v, i, dis);
		}
		dfs1(1, 0);
		dfs2(1, 0);
		for (int i = 1; i <= n; i++)
			printf("%d\n", std::max(u[i], d1[i]));
	}
	return 0;
}
