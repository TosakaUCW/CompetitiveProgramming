#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;
const int M = 1e7 + 5;

int n, m;
int val[N], wei[N], f[M];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &val[i], &wei[i]);
    for (int i = 1; i <= n; i++)
        for (int j = wei[i]; j <= m; j++)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    printf("%d", f[m]);
    return 0;
}