#include <queue>
#include <stdio.h>
#include <vector>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

using std::queue;

const int N = 1e5;
const int M = 2e5;
const int INF = 2147483647;
int n, m, start;
int num_edge, dis[N + 5], head[N + 5];
bool vis[N + 5];

struct cmp
{
	bool operator()(int a, int b)
	{
		return dis[a] > dis[b];
	}
};
std::priority_queue<int, std::vector<int>, cmp> q;

struct node
{
	int next, to, dis;
} edge[M + 5];

void add_edge(int from, int to, int dis)
{
	++num_edge;
	edge[num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;
}

void SPFA(int start)
{
	Rep(i, 1, n) dis[i] = INF;
	dis[start] = 0;
	q.push(start);
	vis[start] = true;
	while (!q.empty())
	{
		int u = q.top();
		q.pop(), vis[u] = false;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].dis)
			{
				dis[v] = dis[u] + edge[i].dis;
				if (!vis[v])
					q.push(v), vis[v] = true;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &start);
	Rep(i, 1, m)
	{
		int from, to, dis;
		scanf("%d%d%d", &from, &to, &dis);
		add_edge(from, to, dis);
	}
	SPFA(start);
	Rep(i, 1, n) printf("%d ", dis[i]);
	return 0;
}
