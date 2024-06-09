#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 20 + 5;

int n, ans, pos;
int a[N];
int con[N][N];
int f[N], pre[N];

void print(int x)
{
    if (pre[x] == 0)
    {
        printf("%d ", x);
        return;
    }
    print(pre[x]);
    printf("%d ", x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[i] = a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &con[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j and con[j][i] and f[j] + a[i] > f[i])
                f[i] = f[j] + a[i], pre[i] = j;
    for (int i = 1; i <= n; i++)
        if (f[i] > ans)
            ans = f[i], pos = i;
    print(pos);
    printf("\n%d", ans);
    return 0;
}