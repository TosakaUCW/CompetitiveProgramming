#include <stdio.h>

const int N = 500 + 5;

int n, m;
int a[N][N], b[N][N];

void change(int x, int y)
{
    a[x][y] = a[x][y] == 1 ? 0 : 1;
    a[x + 1][y] = a[x + 1][y] == 1 ? 0 : 1;
    a[x][y + 1] = a[x][y + 1] == 1 ? 0 : 1;
    a[x + 1][y + 1] = a[x + 1][y + 1] == 1 ? 0 : 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &b[i][j]);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j] != b[i][j])
                change(i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != b[i][j])
            {
                puts("No");
                return 0;
            }
    puts("Yes");
    return 0;
}