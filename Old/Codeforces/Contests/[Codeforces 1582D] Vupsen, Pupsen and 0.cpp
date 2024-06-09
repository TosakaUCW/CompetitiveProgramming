#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n;
int a[N], b[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    if (n & 1)
    {
        if (a[1] != a[3])
            printf("%lld %lld %lld ", -a[2], a[1] - a[3], a[2]);
        else
            printf("%lld %lld %lld ", -a[2], a[1] + a[3], -a[2]);
        for (int i = 4; i <= n; i += 2)
            printf("%lld %lld ", a[i + 1], -a[i]);
    }
    else
        for (int i = 1; i <= n / 2; i++)
            printf("%lld %lld ", a[i * 2], -a[i * 2 - 1]);
    puts("");
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
