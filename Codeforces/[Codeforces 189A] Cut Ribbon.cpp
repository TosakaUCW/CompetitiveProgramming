#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 4e3 + 5;

int n, a[4], f[N];

int main()
{
    memset(f, -1, sizeof f);
    scanf("%d%d%d%d", &n, &a[1], &a[2], &a[3]);
    f[0] = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = a[i]; j <= n; j++)
            if (f[j - a[i]] != -1)
                f[j] = std::max(f[j], f[j - a[i]] + 1);
    printf("%d", f[n]);
    return 0;
}