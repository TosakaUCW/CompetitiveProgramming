#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;

int n, m;
int wei[N], val[N], num[N], f[N];

int main()
{
    int a, b, c, d;
    scanf("%d:%d %d:%d %d", &a, &b, &c, &d, &n);
    m = (c - a) * 60 + d - b;
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &wei[i], &val[i], &num[i]);
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            for (int j = wei[i]; j <= m; j++)
                f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
        }
        else if (num[i] == 1)
        {
            for (int j = m; j >= wei[i]; j--)
                f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
        }
        else
        {
            for (int j = m; j; j--)
                for (int k = 1; k <= num[i] and k * wei[i] <= j; k++)
                    f[j] = std::max(f[j], f[j - k * wei[i]] + val[i] * k);
        }
    }
    printf("%d", f[m]);
    return 0;
}