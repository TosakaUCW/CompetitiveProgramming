#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 500;
const int INF = 1 << 30;

int n, num_edge, num_ans;
int head[N + 5], deg[N + 5];
char ans[N + 5];
bool vis[N + 5], g[N + 5][N + 5];

void dfs(int u)
{
    Rep(v, 64, 125)
    {
        if (g[u][v])
        {
            g[u][v] = false;
            g[v][u] = false;
            dfs(v);
        }
    }
    ans[++num_ans] = u;
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        char s[2];
        scanf("%s", &s);
        g[s[0]][s[1]] = true;
        deg[s[0]]++;
        g[s[1]][s[0]] = true;
        deg[s[1]]++;
    }
    int count = 0;
    int start = 0;
    Rep(i, 64, 125)
    {
        if (deg[i] % 2)
        {
            count++;
            if (!start)
                start = i;
        }
    }
    if (!start)
        Rep(i, 64, 125)
        {
            if (deg[i])
            {
                start = i;
                break;
            }
        }
    if (count and count != 2)
    {
        printf("No Solution");
        return 0;
    }
    dfs(start);
    if (num_ans != n + 1)
    {
        printf("No Solution");
        return 0;
    }
    for (int i = num_ans; i >= 1; i--)
        printf("%c", ans[i]);
    return 0;
}