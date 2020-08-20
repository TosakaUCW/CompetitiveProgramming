#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 2e2 + 5;

int n;
int dis[N][N], f[N];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &dis[i][j]);
    f[1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            f[j] = std::min(f[j], f[i] + dis[i][j]);
    printf("%d", f[n]);
    return 0;
}