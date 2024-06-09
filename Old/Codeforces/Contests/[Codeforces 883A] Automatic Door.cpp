#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 2e5 + 5;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int n, m, a, d, nowt, ans = 1, t[N];

signed main()
{
    n = read(), m = read(), a = read(), d = read();
    for (int i = 1; i <= m; i++)
        t[i] = read();
    int k = d / a + 1;
    nowt = std::min(t[1], a) + d;
    for (int i = 1; i <= m; i++)
        if (t[i] > nowt)
        {
            int L = nowt / a, R = std::min(t[i] / a, n);
            if (L == R)
                nowt = t[i] + d, ++ans;
            else
            {
                int t1 = R - L, t2 = t1 / k + (t1 % k != 0);
                ans += t2, L += (t2 - 1) * k;
                if ((L + 1) * a + d >= t[i])
                    nowt = (L + 1) * a + d;
                else
                    nowt = t[i] + d, ans++;
            }
        }
    int t1 = nowt / a;
    if (t1 < n)
        ans += (n - t1) / k + ((n - t1) % k != 0);
    return printf("%lld", ans), 0;
}