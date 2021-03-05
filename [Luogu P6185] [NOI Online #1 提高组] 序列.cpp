#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
int bel[N], tot[2];
int fa[N], sum[N];
std::vector<std::pair<int, int>> opt;
std::vector<int> G[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

bool dfs(int u, int k)
{
    bel[u] = k, tot[k] += sum[u];
    bool flag = true;
    for (auto v : G[u])
    {
        if (bel[v] == bel[u])
            flag = false;
        if (!bel[v] and !dfs(v, 3 - k))
            flag = false;
    }
    return flag;
}

bool solve()
{

    n = read(), m = read(), opt.clear();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i, sum[i] = bel[i] = 0, G[i].clear();
    for (int i = 1, t, u, v; i <= m; i++)
    {
        t = read(), u = read(), v = read();
        if (t == 2)
            fa[find(u)] = find(v);
        else
            opt.push_back(std::make_pair(u, v));
    }
    for (int i = 1; i <= n; i++)
        sum[find(i)] += b[i] - a[i];
    for (auto x : opt)
    {
        int u = find(x.first), v = find(x.second);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (find(i) == i and !bel[i])
        {
            tot[1] = tot[2] = 0;
            bool flag = dfs(i, 1);
            if (flag and tot[1] != tot[2])
                return false;
            if (!flag and ((tot[1] ^ tot[2]) & 1))
                return false;
        }
    return true;
}

signed main()
{
    for (int T = read(); T--;)
        puts(solve() ? "YES" : "NO");
    return 0;
}