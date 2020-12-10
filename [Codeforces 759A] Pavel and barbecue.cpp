#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;

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

int n, a[N], b[N], ans, cnt;
bool vis[N];

void dfs(int x)
{
    vis[x] = 1;
    if (!vis[a[x]])
        dfs(a[x]);
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read(), cnt += b[i];
    ans += (cnt % 2 == 0), cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            cnt++, dfs(i);
    return printf("%d", ans + (cnt == 1 ? 0 : cnt)), 0;
}