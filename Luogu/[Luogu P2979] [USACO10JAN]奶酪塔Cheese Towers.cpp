#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;
int n, m, h, ans, w[N + 5], v[N + 5], f[2 * N + 5];

int main()
{
    scanf("%d%d%d", &n, &m, &h);
    Rep(i, 1, n)
    {
        scanf("%d%d", &v[i], &w[i]);
        Rep(j, w[i], m * 5 / 4)
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
    }
    ans = f[m];
    Rep(i, 1, n) if (w[i] >= h)
        ans = std::max(ans, f[(m - w[i]) * 5 / 4] + v[i]);
    printf("%d", ans);
    return 0;
}