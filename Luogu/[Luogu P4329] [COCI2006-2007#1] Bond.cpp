#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 20 + 1;

int n;
double c[N][N], f[1 << N];

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
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = read() / 100.0;
    f[0] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        int k = 1;
        for (int tmp = i; tmp; tmp -= tmp & (-tmp))
            k++;
        for (int j = 1; j <= n; j++)
            if (!(i & (1 << (j - 1))))
                f[i | (1 << (j - 1))] = std::max(f[i | (1 << (j - 1))], f[i] * c[j][k]);
    }
    printf("%f", f[(1 << n) - 1] * 100);
    return 0;
}