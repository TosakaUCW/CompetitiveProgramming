#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e6 + 5;

int sum[10][N];

int f(int x)
{
    int res = 1;
    for (; x; x /= 10)
        res *= std::max(x % 10, 1);
    return res;
}

int g(int x) { return x < 10 ? x : g(f(x)); }

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

int main()
{
    sum[0][0] = 1;
    for (int i = 1; i <= N - 5; i++)
        for (int j = 0, x = g(i); j <= 9; j++)
            sum[j][i] = sum[j][i - 1] + (j == x);
    for (int q = read(), l, r, k; q--;)
        l = read(), r = read(), k = read(), printf("%d\n", sum[k][r] - sum[k][l - 1] * (l != 0));
    return 0;
}