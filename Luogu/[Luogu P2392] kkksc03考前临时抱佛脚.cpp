#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 20 + 5;
const int M = 2e3 + 5;

int n[5], m[5], ans;
int wei[N], f[M];

int main()
{
    for (int i = 1; i <= 4; i++)
        scanf("%d", &n[i]);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= n[i]; j++)
            scanf("%d", &wei[j]), m[i] += wei[j];
        memset(f, 0, sizeof f);
        for (int k = 1; k <= n[i]; k++)
            for (int l = m[i] / 2; l >= wei[k]; l--)
                f[l] = std::max(f[l], f[l - wei[k]] + wei[k]);
        ans += std::max(f[m[i] / 2], m[i] - f[m[i] / 2]);
    }
    printf("%d", ans);
    return 0;
}