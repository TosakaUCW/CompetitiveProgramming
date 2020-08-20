#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;
const int INF = 2147483647;

int c, d, n, m, k, ans = INF;
int f[N];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    f[0] = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (i >= n)
            f[i] = std::min(f[i], f[i - n] + c);
        f[i] = std::min(f[i], f[i - 1] + d);
    }
    for (int i = n * m - k; i <= n * m; i++)
        ans = std::min(ans, f[i]);
    printf("%d", ans);
    return 0;
}