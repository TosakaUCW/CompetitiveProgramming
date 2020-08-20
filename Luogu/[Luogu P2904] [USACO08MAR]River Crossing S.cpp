#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;

int n, m;
int a[N], sum[N];
int f[N];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        sum[i] += m * 2;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = std::min(f[j], f[j - i] + sum[i]);
    printf("%d", f[n] - m);
    return 0;
}