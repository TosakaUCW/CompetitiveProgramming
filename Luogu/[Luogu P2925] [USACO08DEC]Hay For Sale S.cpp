#include <stdio.h>
#include <algorithm>

const int N = 5e4 + 5;
const int M = 5e5 + 5;

int n, m;
int val[N], f[N];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= val[i]; j--)
        {
            f[j] = std::max(f[j], f[j - val[i]] + val[i]);
            if (f[m] == m)
            {
                printf("%d", m);
                return 0;
            }
        }
    printf("%d", f[m]);
    return 0;
}