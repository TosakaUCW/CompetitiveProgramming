#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e7 + 5;

int T, a, b, ans;
bool vis[N];

void dfs(int x, bool flag)
{
    if (vis[x] or x > T)
        return;
    vis[x] = true;
    ans = std::max(ans, x);
    if (ans == T)
    {
        printf("%d", ans);
        exit(0);
    }
    dfs(x + a, flag);
    dfs(x + b, flag);
    if (flag)
        dfs(x / 2, !flag);
}

int main()
{
    scanf("%d%d%d", &T, &a, &b);
    dfs(0, true);
    printf("%d", ans);
    return 0;
}