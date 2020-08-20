#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int M = 1e4 + 5;

int n, m;
int wei[N], f[M];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &wei[i]);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= wei[i]; j--)
            f[j] += f[j - wei[i]];
    printf("%d", f[m]);
    return 0;
}