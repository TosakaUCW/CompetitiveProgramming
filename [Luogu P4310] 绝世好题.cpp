#include <stdio.h>

int read(int x = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return x;
}

const int N = 1e5 + 5;

int n, a[N], f[N], max;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), f[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j and f[i] <= max; j--)
            if ((a[j] & a[i]) != 0 and f[j] + 1 > f[i])
                f[i] = f[j] + 1;
        if (f[i] > max) max = f[i];
    }
    printf("%d", max);
    return 0;
}
