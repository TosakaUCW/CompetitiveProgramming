#include <stdio.h>
#include <algorithm>
#include <memory.h>
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

const int N = 1e6 + 5;

int n, m, a[N];

std::vector<int> solve(int L, int R)
{
    std::vector<int> res(R - L + 2, -1LL << 60);
    res[0] = 0;
    if (L > R)
        return res;
    int pos = std::min_element(a + L, a + R + 1) - a;
    std::vector<int> x = solve(L, pos - 1), y = solve(pos + 1, R);
    for (int i = 0; i < x.size(); i++)
        for (int j = 0; j < y.size(); j++)
        {
            res[i + j] = std::max(res[i + j], x[i] + y[j] - 2 * i * j * a[pos]);
            res[i + j + 1] = std::max(res[i + j + 1], x[i] + y[j] - (2 * (i + 1) * (j + 1) - 1) * a[pos] + m * a[pos]);
        }
    return res;
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    printf("%lld", solve(1, n)[m]);
    return 0;
}