#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N], b[N], c[N], d[N], ans;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int j = 20; ~j; j--)
    {
        for (int i = 1; i <= n; i ++)
            b[i] = b[i - 1] + ((a[i] >> j) & 1),
            c[i] ^= (b[i] & 1) << j;
        memset(d, -1, sizeof d);
        d[0] = 0;
        for (int i = 1; i <= n; i ++)
            if (~d[c[i]])
            {
                int &x = d[c[i]];
                b[i] - b[x] == i - x ? ans = std::max(ans, i - x) : x = i;
            }
            else
                d[c[i]] = i;
    }
    printf("%d", ans);
    return 0;
}
