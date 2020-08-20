#include <stdio.h>
#include <algorithm>

const int N = 4e3 + 5;
const int V = 2e5 + 5;

int n, v;
int wei[N], val[N], f[V];

int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]);
    for (int i = 1; i <= n; i++)
        for (int j = v; j >= wei[i]; j--)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    printf("%d", f[v]);
    return 0;
}