#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e4 + 5;

int n, k, a, b, c, d;

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
    n = read(), k = read(), a = read(), b = read(), c = read(), d = read();
    if (k < n + 1 or n == 4)
        return puts("-1"), 0;
    printf("%d %d ", a, c);
    for (int i = 1; i <= n; i++)
        if (i != a and i != b and i != c and i != d)
            printf("%d ", i);
    printf("%d %d\n%d %d ", d, b, c, a);
    for (int i = 1; i <= n; i++)
        if (i != a and i != b and i != c and i != d)
            printf("%d ", i);
    return printf("%d %d\n", b, d), 0;
}