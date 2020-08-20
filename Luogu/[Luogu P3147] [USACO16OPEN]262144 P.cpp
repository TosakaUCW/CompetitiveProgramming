#include <stdio.h>
#include <algorithm>

const int N = 27e4 + 5;
const int M = 100 + 5;

int n, ans;
int a[N];
int f[M][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[a[i]][i] = i + 1;
    for (int i = 2; i <= 58; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!f[i][j])
                f[i][j] = f[i - 1][f[i - 1][j]];
            if (f[i][j])
                ans = i;
        }
    printf("%d", ans);
    return 0;
}