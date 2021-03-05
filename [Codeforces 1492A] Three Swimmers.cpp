#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

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
        int p = read(), a = read(), b = read(), c = read();
        a = (p / a + (p % a != 0)) * a - p;
        b = (p / b + (p % b != 0)) * b - p;
        c = (p / c + (p % c != 0)) * c - p;
        printf("%lld\n", std::min(a, std::min(b, c)));
    }
    return 0;
}