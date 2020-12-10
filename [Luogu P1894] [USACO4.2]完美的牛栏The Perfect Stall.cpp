// luogu-judger-enable-o2
#include <stdio.h>
#include <memory.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e2;

int n, m, ans;
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
    scanf("%d%d", &n, &m);
    Rep(u, 1, n)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int v;
            scanf("%d", &v);
            g[u][v] = 1;
        }
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