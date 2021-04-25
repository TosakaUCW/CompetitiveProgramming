#include <stdio.h>
#include <algorithm>

#define flush fflush(stdout)

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x= x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;
const int M = N << 1;

int n;
int head[N], num_edge;
bool col[N], vis[N];
struct Node { int val, idx; } a[N];
struct Edge { int next, to; } edge[M];
void add_edge(int u, int v) { edge[++num_edge] = {head[u], v}, head[u] = num_edge; }

#define val(i) (a[i].val)
#define idx(i) (a[i].idx)

void dfs(int u, int fa)
{
	if (vis[u]) return;
	col[u] = col[fa] ^ 1, vis[u] = true;
	for (int i = head[u], v; i; i = edge[i].next)
		if ((v = edge[i].to) != fa) 
			dfs(v, u);
}

int main()
{
	n = read(), flush;
	if (n & 1)
	{
		puts("Second"), flush;
		for (int i = 1; i <= 2 * n; i++) a[i] = {i, read()};
		flush;
		for (int i = 1; i <= n; i++)
			if (idx(i) != idx(i + n))
				add_edge(i, i + n), add_edge(i + n, i);
		std::sort(a + 1, a + 1 + 2 * n, [](Node a, Node b) { return a.idx < b.idx; });
		for (int i = 1; i <= 2 * n; i += 2)
			add_edge(val(i), val(i + 1)), add_edge(val(i + 1), val(i));
		for (int i = 1; i <= 2 * n; i++) dfs(i, 0);
		int sum = 0;
		for (int i = 1; i <= 2 * n; i++)
			if (col[i]) sum = (sum + i) % (2 * n);
		sum = bool(sum) ^ 1;
		flush;
		for (int i = 1; i <= 2 * n; i++)
			if (col[i] == sum) printf("%d ", i);
	}
	else
	{
		puts("First"), flush;
		for (int i = 1; i <= n; i++) printf("%d ", i);
		flush;
		for (int i = 1; i <= n; i++) printf("%d ", i);
	}
	return 0;
}
