#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

using std::max;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int INF = 0x7f7f7f7f7f7f7f7f;

int n, ans;
int f[N], g[N];
int son[N], w[N], ind[N];
std::queue<int> Q;

int solve(int u)
{
    int v = son[u];
    int m1 = f[u], m2 = f[u], s = w[u];
    int ans1 = g[u], ans2 = -INF;
    for (; u != v; v = son[v])
    {
        ind[v] = 0;
        ans1 = max(ans1, max(g[v], f[v] + s + m1));
        ans2 = max(ans2, f[v] - s + m2);
        m1 = max(m1, f[v] - s);
        m2 = max(m2, f[v] + s);
        s += w[v];
    }
    return max(ans1, ans2 + s);
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        ++ind[son[i] = read()], w[i] = read();
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q.push(i);
    for (int u; !Q.empty();)
    {
        u = Q.front(), Q.pop();
        int x = f[u] + w[u], v = son[u];
        g[v] = max(g[v], max(f[v] + x, g[u]));
        f[v] = max(f[v], x);
        if (!--ind[v])
            Q.push(v);
    }
    for (int i = 1; i <= n; i++)
        if (ind[i])
            ans += solve(i);
    return printf("%lld", ans), 0;
}