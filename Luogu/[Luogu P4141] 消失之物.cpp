#include <stdio.h>

const int N = 2e3 + 5;

int n, m;
int wei[N], f[N], g[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &wei[i]);
    f[0] = g[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= wei[i]; j--)
            (f[j] += f[j - wei[i]]) %= 10;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < wei[i])
                g[j] = f[j] % 10;
            else
                g[j] = (f[j] - g[j - wei[i]] + 10) % 10;
            printf("%d", g[j]);
        }
        puts("");
    }
    return 0;
}