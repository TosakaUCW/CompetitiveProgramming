#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int n, k, ans;

int main()
{
    freopen("tuna.in", "r", stdin), freopen("tuna.out", "w", stdout);
    n = read(), k = read();
    for (int x, y; n--;)
        x = read(), y = read(), ans += abs(x - y) <= k ? std::max(x, y) : read();
    return printf("%d", ans), 0;
}