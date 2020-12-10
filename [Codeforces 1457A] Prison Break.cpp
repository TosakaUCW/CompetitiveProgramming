#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, m, r, c;

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
    for (int T = read(); T--;)
    {
        n = read(), m = read(), r = read(), c = read();
        printf("%lld\n", std::max(r - 1, n - r) + std::max(c - 1, m - c));
    }
    return 0;
}