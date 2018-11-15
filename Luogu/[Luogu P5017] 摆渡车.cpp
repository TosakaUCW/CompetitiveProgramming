#include <limits.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int T = 4e6;
const int INF = INT_MAX;

int n, m, t, ans = INF;
int cnt[T + 5], sum[T + 5], f[T + 5];

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
    {
        int ti;
        scanf("%d", &ti);
        t = std::max(t, ti);
        cnt[ti]++;
        sum[ti] += ti;
    }
    Rep(i, 1, t + m)
    {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    Rep(i, 1, t + m)
    {
        if (i >= m and cnt[i - m] == cnt[i])
        {
            f[i] = f[i - m];
            continue;
        }
        f[i] = cnt[i] * i - sum[i];
        Rep(j, std::max(1, i - 2 * m), i - m)
            f[i] = std::min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
    }
    Rep(i, t, t + m)
        ans = std::min(ans, f[i]);
    printf("%d", ans);
    return 0;
}