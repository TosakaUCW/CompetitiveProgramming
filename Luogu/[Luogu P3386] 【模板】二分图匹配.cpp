// luogu-judger-enable-o2
#include <stdio.h>
#include <memory.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;

int n, m, e, ans;
int g[N + 5][N + 5], match[N + 5];
bool used[N + 5];

bool dfs(int u)
{
    Rep(v, 1, m)
    {
        if (g[u][v] and !used[v])
        {
            used[v] = true;
            if (!match[v] or dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    Rep(i, 1, e)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
    }
    Rep(i, 1, n)
    {
        memset(used, false, sizeof(used));
        if (dfs(i))
            ans++;
    }
    printf("%d", ans);
    return 0;
}