#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 4e2 + 5;
const int M = 1.2e3 + 5;
const int P = 998244353;

int n, m, d[N][N];
int head[N], num_edge;

struct Node { int next, to; } edge[M];
void add_edge(int u, int v) { edge[++num_edge] = {head[u], v}, head[u] = num_edge; }

int solve(int s, int t)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (d[s][t] == d[s][i] + d[t][i])
			++cnt;
	if (cnt != d[s][t] + 1) return 0;
	int ans = 1;
	for (int u = 1; u <= n; u++)
		if (d[s][t] != d[s][u] + d[t][u])
		{
			int x = 0;
			for (int i = head[u], v; i; i = edge[i].next)
			{
				v = edge[i].to;
				if (d[s][u] == d[s][v] + 1 and d[t][u] == d[t][v] + 1)
					++x;
			}
			ans = ans * x % P;
		}
	return ans;
}

signed main()
{
	n = read(), m = read(), memset(d, 0x3f, sizeof d);
	for (int i = 1, u, v; i <= m; i++)
		u = read(), v = read(), 
		d[u][v] = d[v][u] = 1,
		add_edge(u, v), add_edge(v, u);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= n; j++)
			printf("%lld ", solve(i, j));
	return 0;
}
