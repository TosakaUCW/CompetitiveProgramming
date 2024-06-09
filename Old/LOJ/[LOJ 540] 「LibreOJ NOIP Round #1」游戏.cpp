#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>
#include <queue>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 500 + 5;

int n = 500, k;
int g[N][N];

signed main()
{
    k = read(), g[1][2] = 1;
    for (int i = 3; i <= n; i++)
    {
        int p = -1;
        for (int j = i - 1; j; j--)
            if (j * (j - 1) / 2 <= k)
            {
                p = j;
                break;
            }
        k -= p * (p - 1) / 2;
        for (int j = 1; j <= p; j++)
            g[j][i] = 1;
        if (!k)
        {
            n = i;
            break;
        }
    }
    printf("%lld\n", n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            printf("%lld ", g[i][j]);
        puts("");
    }
    return 0;
}