#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, m;
int a[N], f[N];

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
    memset(f, 127, sizeof f);
    n = read(), m = read();
    for (int i = 1, x; i <= n; i++)
        x = read(), a[i] = a[i - 1] + (x == 1 ? 1 : -1);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (abs(a[i] - a[j - 1]) <= m or abs(a[i] - a[j - 1]) == i - j + 1)
                f[i] = std::min(f[i], f[j - 1] + 1);
    printf("%d", f[n]);
    return 0;
}