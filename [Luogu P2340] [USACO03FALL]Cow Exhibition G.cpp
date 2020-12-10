#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 4e2 + 5;
const int M1 = 4e5;
const int M2 = 8e5;

int n, ans;
int a[N], b[N];
int f[M2 + 5];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    memset(f, 0xcf, sizeof f);
    f[M1] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= 0)
            for (int j = M2; j >= a[i]; j--)
                f[j] = std::max(f[j], f[j - a[i]] + b[i]);
        else
            for (int j = 0; j <= M2 + a[i]; j++)
                f[j] = std::max(f[j], f[j - a[i]] + b[i]);
    for (int i = M1; i <= M2; i++)
        if (f[i] > 0)
            ans = std::max(ans, f[i] + i - M1);
    printf("%d", ans);
    return 0;
}