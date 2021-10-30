#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 18 + 5;
const int INF = 2147483647;

int n, k, ans;
int a[N], Pow[N];

void solve()
{
    n = read(), k = read() + 1, ans = 0, a[n + 1] = 18;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, x; i <= n; i++)
    {
        x = std::min(k, Pow[a[i + 1] - a[i]] - 1);
        ans += x * Pow[a[i]], k -= x;
    }
    printf("%lld\n", ans);
}

signed main()
{
    Pow[0] = 1;
    for (int i = 1; i <= 18; i++)
        Pow[i] = Pow[i - 1] * 10;
    for (int T = read(); T--; solve())
        ;
    return 0;
}