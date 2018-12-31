#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 100 + 5;
const int M = 10 + 5;

int n;
int f[N][M][M][M];
char a[N];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d\n", &n);
    Rep(i, 1, n)
        scanf("%c\n", &a[i]);
    f[0][0][0][0] = 0;
    Rep(i, 1, n)
        Rep(j, 0, 10)
            Rep(k, 0, 10)
                Rep(l, 0, 10)
                {
                    if (j + k + l > 10)
                        continue;
                    if (a[i] == 'A' and j)
                        f[i][j][k][l] = f[i - 1][j - 1][k][l];
                    if (a[i] == 'B' and k)
                        f[i][j][k][l] = f[i - 1][j][k - 1][l];
                    if (a[i] == 'C' and l)
                        f[i][j][k][l] = f[i - 1][j][k][l - 1];
                    f[i][0][k][l] = std::min(f[i][0][k][l], f[i][j][k][l] + 1);
                    f[i][j][0][l] = std::min(f[i][j][0][l], f[i][j][k][l] + 1);
                    f[i][j][k][0] = std::min(f[i][j][k][0], f[i][j][k][l] + 1);
                }
    printf("%d\n", f[n][0][0][0]);
    return 0;
}