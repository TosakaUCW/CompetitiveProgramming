#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, tot, len;
int val[N], a[N], ch[N][2];
int d[N], f[N];

void dfs(int u)
{
    if (ch[u][0])
        dfs(ch[u][0]);
    a[++tot] = val[u];
    if (ch[u][1])
        dfs(ch[u][1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 2; i <= n; i++)
    {
        int fa, x;
        scanf("%d%d", &fa, &x);
        ch[fa][x] = i;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        a[i] -= i;
    for (int i = 1; i <= n; i++)
    {
        f[i] = std::lower_bound(d + 1, d + len + 1, a[i]) - d;
        d[f[i]] = a[i];
        len = std::max(len, f[i]);
    }
    printf("%d", n - len);
    return 0;
}