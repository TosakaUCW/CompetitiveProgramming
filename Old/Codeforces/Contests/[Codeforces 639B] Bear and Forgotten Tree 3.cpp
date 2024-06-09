#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, h, d;

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
    n = read(), d = read(), h = read();
    if (n - 1 < d or h * 2 < d or (d == h and d == 1 and n > 2))
    {
        puts("-1");
        return 0;
    }
    if (d == h)
    {
        for (int i = 2; i <= h + 1; i++)
            printf("%d %d\n", i - 1, i);
        for (int i = h + 2; i <= n; i++)
            printf("2 %d\n", i);
        return 0;
    }
    for (int i = 2; i <= h + 1; i++)
        printf("%d %d\n", i - 1, i);
    for (int i = h + 2, last = 1; i <= d + 1; i++)
        printf("%d %d\n", last, i), last = i;
    for (int i = d + 2; i <= n; i++)
        printf("1 %d\n", i);
    return 0;
}