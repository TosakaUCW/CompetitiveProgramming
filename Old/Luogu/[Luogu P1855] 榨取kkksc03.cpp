#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int Y = 2e2 + 5;

int n, M, T;
int m[N], t[N], f[Y][Y];

int main()
{
    scanf("%d%d%d", &n, &M, &T);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &m[i], &t[i]);
    for (int i = 1; i <= n; i++)
        for (int j = M; j >= m[i]; j--)
            for (int k = T; k >= t[i]; k--)
                f[j][k] = std::max(f[j][k], f[j - m[i]][k - t[i]] + 1);
    printf("%d", f[M][T]);
    return 0;
}