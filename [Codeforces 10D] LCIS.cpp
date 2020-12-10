#include <stdio.h>
#include <algorithm>
#include <stack>

const int N = 5e3 + 5;

int n, m, ans;
int a[N], b[N];
int f[N][N], pre[N][N];
int stack[N], size;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
    {
        int val = 0, pos = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                f[i][j] = val + 1, pre[i][j] = pos;
            else
                f[i][j] = f[i - 1][j], pre[i][j] = j;
            if (b[j] < a[i])
                if (f[i - 1][j] > val)
                    val = f[i - 1][j], pos = j;
        }
    }
    int i = n, j;
    for (int i = 1; i <= m; i++)
        if (f[n][i] > ans)
            ans = f[n][i], j = i;
    printf("%d\n", ans);
    if (!ans)
        return 0;
    while (i or j)
    {
        if (pre[i][j] != j)
            stack[++size] = b[j];
        j = pre[i--][j];
    }
    for (int i = size; i; i--)
        printf("%d ", stack[i]);
    return 0;
}