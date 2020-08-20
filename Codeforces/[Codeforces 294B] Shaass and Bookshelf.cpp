#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 5;
const int INF = 2147483647 / 2;

int n, m;
int t[N], w[N], f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &t[i], &w[i]), m += t[i];
    for (int i = 1; i <= m; i++)
        f[i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= t[i]; j--)
            f[j] = std::min(f[j], f[j - t[i]] + w[i]);
    for (int i = m; i >= 0; i--)
        if (m - i >= f[i])
        {
            printf("%d", m - i);
            return 0;
        }
    return 0;
}