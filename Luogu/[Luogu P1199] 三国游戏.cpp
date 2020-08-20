#include <stdio.h>
#include <algorithm>

const int N = 5e2 + 5;

int n, ans;
int a[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &a[i][j]), a[j][i] = a[i][j];
    for (int i = 1; i <= n; i++)
    {
        std::sort(a[i] + 1, a[i] + 1 + n);
        ans = std::max(ans, a[i][n - 1]);
    }
    printf("1\n%d", ans);
    return 0;
}