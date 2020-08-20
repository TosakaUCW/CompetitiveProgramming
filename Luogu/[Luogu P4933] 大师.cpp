#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int H = 2e4 + 5;
const int P = 998244353;

int n;
long long ans, f[N][H * 2];
int a[N];
bool vis[N][H * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j; j--)
        {
            if (!vis[j][a[j] - a[i] + H])
            {
                vis[j][a[j] - a[i] + H] = true;
                f[j][a[j] - a[i] + H]++;
            }
            (ans += f[j][a[j] - a[i] + H]) %= P;
            (f[i][a[j] - a[i] + H] += f[j][a[j] - a[i] + H]) %= P;
        }
    }
    printf("%lld", ans + n);
    return 0;
}