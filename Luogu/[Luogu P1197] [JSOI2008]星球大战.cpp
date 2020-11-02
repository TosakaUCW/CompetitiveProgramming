#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 4e5 + 5;
const int M = N << 1;

int n, m, k, sum;
int head[N], num_edge;
int fa[N], a[N], ans[N];
bool b[N];

struct Node
{
    int next, to, from;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v, u}, head[u] = num_edge; }

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void merge(int x, int y)
{
    int dx = find(x), dy = find(y);
    if (dx != dy)
        fa[dx] = dy, sum--;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1, u, v; i <= m; i++)
        u = read() + 1, v = read() + 1, add_edge(u, v), add_edge(v, u);
    k = read(), sum = n - k;
    for (int i = 1; i <= k; i++)
        a[i] = read() + 1, b[a[i]] = true;
    for (int i = 1; i <= 2 * m; i += 2)
    {
        int x = edge[i].from, y = edge[i].to;
        if (!b[x] and !b[y])
            merge(x, y);
    }
    ans[k + 1] = sum;
    for (int i = k; i; i--)
    {
        int x = a[i];
        b[x] = false, sum++;
        for (int i = head[x]; i; i = edge[i].next)
        {
            int x = edge[i].from, y = edge[i].to;
            if (!b[x] and !b[y])
                merge(x, y);
        }
        ans[i] = sum;
    }
    for (int i = 1; i <= k + 1; i++)
        printf("%d\n", ans[i]);
    return 0;
}