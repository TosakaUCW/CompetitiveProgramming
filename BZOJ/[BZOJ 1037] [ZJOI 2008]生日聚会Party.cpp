#include <stdio.h>
#include <algorithm>

const int K = 20;
const int N = 150;
const int P = 12345678;

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n, m, x,ans;
int f[N + 5][N + 5][K + 5][K + 5];

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    f[0][0][0][0] = 1;
    Rep(i, 0, n)
        Rep(j, 0, m)
            Rep(k, 0, std::min(x, i))
                Rep(l, 0, std::min(x, j))
                {
                    if (k < x)
                        f[i + 1][j][k + 1][std::max(l - 1, 0)] = (f[i + 1][j][k + 1][std::max(l - 1, 0)] + f[i][j][k][l]) % P;
                    if (l < x)
                        f[i][j + 1][std::max(k - 1, 0)][l + 1] = (f[i][j + 1][std::max(k - 1, 0)][l + 1] + f[i][j][k][l]) % P;
                }
    Rep(i, 0, x)
        Rep(j, 0, x)
            ans = (ans + f[n][m][i][j]) % P;
    printf("%d", ans);
    return 0;
}
