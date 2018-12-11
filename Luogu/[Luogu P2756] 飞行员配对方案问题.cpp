// luogu-judger-enable-o2
#include <stdio.h>
#include <memory.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;

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
    int u, v;
    while (scanf("%d%d", &u, &v) and u != -1 and v != -1)
        g[u][v] = 1;
    Rep(i, 1, n)
    {
        memset(used, false, sizeof(used));
        if (dfs(i))
            ans++;
    }
    if (ans == 0)
    {
        printf("No Solution!");
    }
    else
    {
        printf("%d\n", ans);
        Rep(i, n + 1, m)
        {
            if (match[i])
                printf("%d %d\n", match[i], i);
        }
    }
    return 0;
}