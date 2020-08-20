#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 30 + 5;

int n;
ll f[N][N], root[N][N];

void print(int l, int r)
{
    if (l > r)
        return;
    printf("%d ", root[l][r]);
    print(l, root[l][r] - 1), print(root[l][r] + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &f[i][i]), root[i][i] = i;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            f[i][j] = f[i][i] + f[i + 1][j];
            root[i][j] = i;
            for (int k = i + 1; k < j; k++)
                if (f[i][j] < f[i][k - 1] * f[k + 1][j] + f[k][k])
                    f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k], root[i][j] = k;
        }
    printf("%lld\n", f[1][n]);
    print(1, n);
    return 0;
}