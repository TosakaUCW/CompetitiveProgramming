#include <stdio.h>
#include <algorithm>
#include <memory.h>

int n, a, b, ans = 2147483647;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    n = read(), a = read(), b = read();
    for (int i = 0; i <= n / a; ++i)
        ans = std::min(ans, (n - (i * a)) % (b * 5));
    return printf("%d", ans), 0;
}