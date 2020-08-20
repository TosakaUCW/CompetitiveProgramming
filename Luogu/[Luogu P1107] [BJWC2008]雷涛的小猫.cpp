#include <stdio.h>
#include <algorithm>

const int N = 5e3 + 5;

int n, m, delta, ans;
int a[N][N], f[N][N * 2];

struct Node
{
    int val, pos;
} k[N];

int main()
{
    scanf("%d%d%d", &n, &m, &delta);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d", &x);
        while (x--)
            scanf("%d", &y), a[i][y]++;
    }
    // for (int j = m; j >= 0; j--)
    // for (int i = 1; i <= n; i++)
    // k[j] = std::max(k[j], a[i][j]);
    for (int j = m; j >= 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][j] = f[i][j + 1] + a[i][j];
            if (k[j + delta].val + a[i][j] > f[i][j] and k[j + delta].pos != i)
                f[i][j] = k[j + delta].val + a[i][j];
            if (f[i][j] > k[j].val)
                k[j].val = f[i][j], k[j].pos = i;
        }
        // printf("j:%d  k[j].val:%d    k[j].pos:%d\n", j, k[j].val, k[j].pos);
    }
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[i][0]);
    printf("%d", ans);
    return 0;
}