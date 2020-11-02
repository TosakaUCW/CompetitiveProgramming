#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

const int N = 5e3 + 5;
const int M = N << 1;

int n, m;
int from[N], to[N];
std::vector<int> G[N];
int a[N], ans[N], cnt, del;
bool isCir;

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

void dfs(int u, int fa)
{
    if (cnt >= n)
    {
        isCir = true;
        return;
    }
    a[++cnt] = u;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if ((u == from[del] and v == to[del]) or (u == to[del] and v == from[del]) or v == fa)
            continue;
        dfs(v, u);
    }
}

bool judge()
{
    for (int i = 1; i <= n; i++)
        if (!a[i])
            return false;
    for (int i = 1; i <= n; i++)
        if (ans[i] != a[i])
            return ans[i] > a[i];
}

int main()
{
    memset(ans, 0x7f, sizeof ans);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        from[i] = read(), to[i] = read(), G[from[i]].push_back(to[i]), G[to[i]].push_back(from[i]);
    for (int i = 1; i <= n; i++)
        std::sort(G[i].begin(), G[i].end());
    if (m == n - 1)
    {
        cnt = 0;
        dfs(1, 0);
        memcpy(ans, a, sizeof a);
    }
    else
        for (int i = 1; i <= m; i++)
        {
            memset(a, 0, sizeof a);
            cnt = 0, del = i, isCir = false;
            dfs(1, 0);
            if (!isCir and judge())
                memcpy(ans, a, sizeof a);
        }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}