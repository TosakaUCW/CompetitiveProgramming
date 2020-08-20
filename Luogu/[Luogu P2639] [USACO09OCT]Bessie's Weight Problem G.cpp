#include <stdio.h>
#include <algorithm>

const int N = 5e6 + 5;
const int M = 5e6 + 5;

int n, m;
int wei[N], f[N];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &wei[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= wei[i]; j--)
        {
            f[j] = std::max(f[j], f[j - wei[i]] + wei[i]);
            if (f[m] == m)
            {
                printf("%d", m);
                return 0;
            }
        }
    printf("%d", f[m]);
    return 0;
}