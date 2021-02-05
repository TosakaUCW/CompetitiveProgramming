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

int n, m, sum;

int main()
{
    freopen("tarifa.in", "r", stdin), freopen("tarifa.out", "r", stdout);
    sum = m = read(), n = read();
    for (int i = 1; i <= n; i++)
        sum += m - read();
    return printf("%d", sum), 0;
}