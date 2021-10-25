#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = 350 + 5;

int n, a[N], sum[N], f[N][2];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), sum[i] = sum[i - 1] + a[i];
    memset(f, 0, sizeof f);
    int i = 1, k = 0;
    for (; i * (i + 1) / 2 <= n; i++, k ^= 1)
    {
        bool flag = 0;
        for (int j = n - i * (i + 1) / 2 + 1; j; j--)
        {
            if (i == 1 or f[j + i][k ^ 1] > sum[j + i - 1] - sum[j - 1])
                f[j][k] = sum[j + i - 1] - sum[j - 1], flag = 1;
            f[j][k] = std::max(f[j][k], f[j + 1][k]);
        }
        for (int j = n + 1; j; j--)
            f[j][k ^ 1] = 0;
        if (!flag)
            break;
    }
    printf("%lld\n", i - 1);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
