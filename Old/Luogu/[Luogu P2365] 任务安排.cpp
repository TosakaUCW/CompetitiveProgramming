#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e3 + 5;

int n, s;
int f[N], sumT[N], sumC[N];

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
    n = read(), s = read();
    for (int i = 1; i <= n; i++)
        sumT[i] = sumT[i - 1] + read(),
        sumC[i] = sumC[i - 1] + read();
    memset(f, 0x7f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] = std::min(f[i], f[j] + sumT[i] * (sumC[i] - sumC[j]) + s * (sumC[n] - sumC[j]));
    printf("%d", f[n]);
    return 0;
}