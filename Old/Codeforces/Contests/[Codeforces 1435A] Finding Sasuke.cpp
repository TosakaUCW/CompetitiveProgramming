#include <stdio.h>

const int N = 1e5 + 5;

int n, m, a[N];

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
    for (int T = read(); T--; puts(""))
    {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            printf("%d ", (i <= n / 2 ? -1 : 1) * a[n - i + 1]);
    }
    return 0;
}