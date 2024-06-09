#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e2 + 5;
const int M = 10 + 5;

int n;
int f[N][M][M][M];
char str[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    // freopen("worker.in", "r", stdin);
    // freopen("worker.out", "w", stdout);
    memset(f, 0x3f, sizeof f);
    n = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", &str[i]);
    f[0][0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int a = 0; a <= 10; a++)
            for (int b = 0; b <= 10; b++)
                for (int c = 0; c <= 10; c++)
                    if (a + b + c <= 10)
                    {
                        if (a and str[i] == 'A')
                            f[i][a][b][c] = f[i - 1][a - 1][b][c];
                        if (b and str[i] == 'B')
                            f[i][a][b][c] = f[i - 1][a][b - 1][c];
                        if (c and str[i] == 'C')
                            f[i][a][b][c] = f[i - 1][a][b][c - 1];
                        f[i][0][b][c] = std::min(f[i][0][b][c], f[i][a][b][c] + 1);
                        f[i][a][0][c] = std::min(f[i][a][0][c], f[i][a][b][c] + 1);
                        f[i][a][b][0] = std::min(f[i][a][b][0], f[i][a][b][c] + 1);
                    }
    return printf("%d", f[n][0][0][0]), 0;
}