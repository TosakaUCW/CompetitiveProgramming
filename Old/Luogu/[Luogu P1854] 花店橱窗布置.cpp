#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;

int n, m;
int pos, ans;
int a[N][N], f[N][N], pre[N][N];
int stack[N], cnt;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= m - n; i++)
        f[1][i] = a[1][i], pre[1][i] = i;
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= m - n + i; j++)
            for (int k = 1; k < j; k++)
                if (f[i - 1][k] + a[i][j] > f[i][j])
                    f[i][j] = f[i - 1][k] + a[i][j], pre[i][j] = k;
    for (int i = n; i <= m; i++)
        if (f[n][i] > ans)
            ans = f[n][i], pos = i;
    for (int i = n, j = pos;; stack[++cnt] = j, j = pre[i--][j])
        if (pre[i][j] == j)
        {
            stack[++cnt] = j;
            break;
        }
    printf("%d\n", ans);
    for (int i = cnt; i; i--)
        printf("%d ", stack[i]);
    return 0;
}