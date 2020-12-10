#include <stdio.h>
#include <algorithm>

const int N = 5e3 + 5;

int n;
int a[N];
int f[N], g[N];
int ans, tot;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (a[j] > a[i])
                f[i] = std::max(f[i], f[j] + 1);
        if (f[i] == 1)
            g[i] = 1;
        for (int j = 1; j < i; j++)
            if (f[i] == f[j] and a[i] == a[j])
                g[j] = 0;
            else if (f[i] == f[j] + 1 and a[j] > a[i])
                g[i] += g[j];
    }
    for (int i = 1; i <= n; i++)
        if (f[i] > ans)
            ans = f[i];
    for (int i = 1; i <= n; i++)
        if (f[i] == ans)
            tot += g[i];
    printf("%d %d", ans, tot);
    return 0;
}