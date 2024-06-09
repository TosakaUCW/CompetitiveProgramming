#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

const int N = 1e2 + 5;

int n, k, ans = 1 << 30;
int sum[N];
int f[N][N];

struct Node
{
    int h, a;
    bool friend operator<(Node a, Node b) { return a.h < b.h; }
} a[N];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d%d", &n, &k);
    k = n - k;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].h, &a[i].a), sum[i] = sum[i - 1] + a[i].a;
    std::sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; i++)
        f[i][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= k and j <= i; j++)
            for (int p = 1; p < i; p++)
                f[i][j] = std::min(f[i][j], f[i - p][j - 1] + abs(a[i - p].a - a[i].a));
    for (int i = k; i <= n; i++)
        ans = std::min(ans, f[i][k]);
    printf("%d", ans);
    return 0;
}