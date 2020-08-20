#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e7 + 5;

int n, m, k, ans;
int fa[N];

struct Node
{
    int u, v, dis;
    bool friend operator<(Node a, Node b) { return a.dis < b.dis; }
} edge[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

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

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        edge[i].u = read(), edge[i].v = read(), edge[i].dis = read();
    std::sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m and k < n - 1; i++)
    {
        int dx = find(edge[i].u);
        int dy = find(edge[i].v);
        if (dx != dy)
            ans += edge[i].dis, fa[dx] = dy, k++;
    }
    if (k != n - 1)
        puts("orz");
    else
        printf("%d", ans);
    return 0;
}