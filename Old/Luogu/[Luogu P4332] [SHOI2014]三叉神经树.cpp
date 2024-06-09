#include <stdio.h>
#include <algorithm>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 15e5 + 5;
const int M = N * 6;

int n;
int ch[N][2], id[N][2], f[N], add[N], val[N], sum[N];

#define ls ch[p][0]
#define rs ch[p][1]
#define get(x) (ch[f[x]][1] == x)
#define isRoot(x) (ch[f[x]][0] != x and ch[f[x]][1] != x)
void pushUp(int p)
{
    id[p][1] = id[rs][1], id[p][2] = id[rs][2];
    if (!id[p][1])
        id[p][1] = sum[p] != 1 ? p : id[ls][1];
    if (!id[p][2])
        id[p][2] = sum[p] != 2 ? p : id[ls][2];
}
void ADD(int p, int c) { sum[p] += c, val[p] = sum[p] > 1, swap(id[p][1], id[p][2]), add[p] += c; }
void pushDown(int p)
{
    if (add[p])
        ADD(ls, add[p]), ADD(rs, add[p]), add[p] = 0;
}
void Update(int p)
{
    if (!isRoot(p))
        Update(f[p]);
    pushDown(p);
}
void Rotate(int x)
{
    int y = f[x], z = f[y], k = get(x);
    if (!isRoot(y))
        ch[z][ch[z][1] == y] = x;
    ch[y][k] = ch[x][!k], f[ch[y][k]] = y;
    ch[x][!k] = y, f[y] = x, f[x] = z;
    pushUp(y), pushUp(x);
}
void Splay(int x)
{
    Update(x);
    for (int fa; fa = f[x], !isRoot(x); Rotate(x))
        if (!isRoot(fa))
            Rotate(get(x) == get(fa) ? fa : x);
}
int Access(int x, int p = 0)
{
    for (p = 0; x; p = x, x = f[x])
        Splay(x), ch[x][1] = p, pushUp(x);
    return p;
}

int head[N], num_edge;
struct Node
{
    int next, to;
} edge[M];
void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void dfs(int u, int fa)
{
    sum[u] = 0;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs(v, u), sum[u] += val[v];
    if (u <= n)
        val[u] = sum[u] > 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1, x; j <= 3; j++)
            f[x = read()] = i, add_edge(x, i), add_edge(i, x);
    for (int i = n + 1; i <= n * 3 + 1; i++)
        val[i] = read();
    dfs(1, 0);
    int ans = val[1], last, tag, x, w;
    for (int q = read(); q--;)
    {
        x = f[last = read()];
        tag = val[last] ? -1 : 1;
        Access(x), Splay(x);
        w = id[x][val[last] ? 2 : 1];
        if (w)
        {
            Splay(w), ADD(ch[w][1], tag);
            pushUp(ch[w][1]);
            sum[w] += tag, val[w] = sum[w] > 1;
            pushUp(w);
        }
        else
            ans ^= 1, ADD(x, tag), pushUp(x);
        val[last] ^= 1, printf("%d\n", ans);
    }
    return 0;
}