#include <stdio.h>
#include <algorithm>

const int N = 150 + 5;

int n;
int map[N][N], sum[N][N];
long long ans;

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("\n");
        for (int j = 1; j <= n; j++)
        {
            char c;
            scanf("%c", &c);
            map[i][j] = c == 'W' ? 0 : 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!map[i][j])
                for (int k = i; k <= n; k++)
                    for (int l = j; l <= n; l++)
                    {
                        if (map[k][l])
                            break;
                        int x = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];
                        if (x > 0)
                            break;
                        if (x == 0)
                            ans++;
                    }
    printf("%lld", ans);
    return 0;
}