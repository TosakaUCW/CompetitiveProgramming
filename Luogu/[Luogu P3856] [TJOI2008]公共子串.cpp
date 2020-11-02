#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string.h>

const int N = 100 + 5;

int lena, lenb, lenc;
int lasta[N]['z' + 1], lastb[N]['z' + 1], lastc[N]['z' + 1];
long long f[N][N][N];
char a[N], b[N], c[N];

int main()
{
    scanf("%s%s%s", a + 1, b + 1, c + 1);
    lena = strlen(a + 1), lenb = strlen(b + 1), lenc = strlen(c + 1);
    for (int i = 2; i <= lena; lasta[i][a[i - 1]] = i - 1, i++)
        for (int j = 'a'; j <= 'z'; j++)
            lasta[i][j] = lasta[i - 1][j];
    for (int i = 2; i <= lenb; lastb[i][b[i - 1]] = i - 1, i++)
        for (int j = 'a'; j <= 'z'; j++)
            lastb[i][j] = lastb[i - 1][j];
    for (int i = 2; i <= lenc; lastc[i][c[i - 1]] = i - 1, i++)
        for (int j = 'a'; j <= 'z'; j++)
            lastc[i][j] = lastc[i - 1][j];
    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
            for (int k = 1; k <= lenc; k++)
                if (a[i] == b[j] and b[j] == c[k])
                {
                    f[i][j][k] = f[i - 1][j - 1][k - 1] * 2 + 1;
                    if (lasta[i][a[i]] and lastb[j][b[j]] and lastc[k][c[k]])
                        f[i][j][k] -= f[lasta[i][a[i]] - 1][lastb[j][b[j]] - 1][lastc[k][c[k]] - 1] + 1;
                }
                else
                {
                    f[i][j][k] =
                        f[i - 1][j][k] + f[i][j - 1][k] + f[i][j][k - 1] -
                        f[i - 1][j - 1][k] - f[i][j - 1][k - 1] - f[i - 1][j][k - 1] +
                        f[i - 1][j - 1][k - 1];
                }
    printf("%lld", f[lena][lenb][lenc]);
    return 0;
}