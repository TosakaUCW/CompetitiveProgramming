#include <stdio.h>
#include <algorithm>
#include <vector>

const int N = 1e3 + 5;
const int M = 2e4 + 5;

int n, m, cnt[N], max, f[N];

struct Node
{
    int wei, val;
} a[N][N];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int wei, val, idx;
        scanf("%d%d%d", &wei, &val, &idx);
        a[idx][++cnt[idx]].wei = wei;
        a[idx][cnt[idx]].val = val;
        max = std::max(max, idx);
    }
    for (int i = 1; i <= max; i++)
        if (cnt[i])
            for (int j = m; j >= 0; j--)
                for (int k = 1; k <= cnt[i]; k++)
                    if (j >= a[i][k].wei)
                        f[j] = std::max(f[j], f[j - a[i][k].wei] + a[i][k].val);
    printf("%d", f[m]);
    return 0;
}