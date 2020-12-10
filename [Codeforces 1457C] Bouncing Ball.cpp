#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, p, k, x, y, ans = INF;
int val[N];
char a[N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

signed main()
{
    for (int T = read(); T--; printf("%lld\n", ans), ans = INF, memset(val, 0, sizeof val))
    {
        n = read(), p = read(), k = read(), scanf("%s", a + 1), y = read(), x = read();
        for (int i = n; i >= p; i--)
            val[(i - p) % k] += '1' - a[i],
                ans = std::min(ans, x * (i - p) + val[(i - p) % k] * y);
    }
    return 0;
}