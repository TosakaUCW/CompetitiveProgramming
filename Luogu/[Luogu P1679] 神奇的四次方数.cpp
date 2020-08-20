#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, m, wei[N], f[N];

void pre()
{
    int x = 1;
    while (x * x * x * x <= 100000)
        x++;
}

int main()
{
    memset(f, 127, sizeof f);
    for (n = 1; n * n * n * n <= 100000; n++)
        wei[n] = n * n * n * n;
    scanf("%d", &m);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = wei[i]; j <= m; j++)
            f[j] = std::min(f[j], f[j - wei[i]] + 1);
    printf("%d", f[m]);
    return 0;
}