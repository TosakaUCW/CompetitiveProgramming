#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int __int128

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < '0' or ch > '9')
        f = ch == '-', ch = getchar();
    while (ch >= '0' and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar((x % 10) ^ 48);
}

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m;
int num_edge, head[N];
int t[N], oud[N];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

struct Node
{
    int next, to;
} edge[M];
struct node
{
    int cur, a, b;
    node(int _cur = 1, int _a = 0, int _b = 1) { cur = _cur, a = _a, b = _b; }
    node friend operator+(node a, node b)
    {
        a.a = a.a * b.b + a.b * b.a, a.b = a.b * b.b;
        int k = gcd(a.a, a.b);
        if (k)
            a.a /= k, a.b /= k;
        return a;
    }
} dis[N];

std::queue<node> Q;

void add_edge(int u, int v) { edge[++num_edge].next = head[u], edge[num_edge].to = v, head[u] = num_edge; }

void bfs(int s)
{
    node tmp;
    tmp.cur = s, tmp.a = tmp.b = 1;
    Q.push(tmp);
    for (node u; !Q.empty();)
    {
        u = Q.front(), Q.pop(), u.b *= oud[u.cur];
        for (int i = head[u.cur], v; i; i = edge[i].next)
            v = edge[i].to,
            dis[v] = dis[v] + u,
            tmp.cur = v, tmp.a = u.a, tmp.b = u.b,
            Q.push(tmp);
    }
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        if (!(oud[i] = read()))
            t[++t[0]] = i;
        for (int j = 1, x; j <= oud[i]; j++)
            x = read(), add_edge(i, x);
    }
    for (int i = 1; i <= m; i++)
        bfs(i);
    for (int i = 1; i <= t[0]; i++)
        write(dis[t[i]].a), putchar(' '), write(dis[t[i]].b), putchar('\n');
    return 0;
}
