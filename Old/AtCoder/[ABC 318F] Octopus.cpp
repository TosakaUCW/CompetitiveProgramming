#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e2 + 5;

int n, m, ans;
int a[N], b[N], k;
std::vector<int> S;
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            S.emplace_back(a[i] + b[j]), S.emplace_back(a[i] - b[j] - 1);
    m = S.size(), std::sort(S.begin(), S.end());
    for (int i = 1; i < m; i++)
    {
        k = S[i];
        std::sort(a + 1, a + 1 + n, [](int a, int b)
                  { return abs(a - k) < abs(b - k); });
        bool f = 1;
        for (int j = 1; j <= n; j++)
            f &= (abs(a[j] - k) <= b[j]);
        ans += f * (S[i] - S[i - 1]);
    }
    printf("%lld", ans);
    return 0;
}
/*
-L <= x - k <= +L
di = abs(xi - k)
di <= Li
k ok and k + 1 is not ok ? -> abs(xi - k) == li
*/