#include <stdio.h>
#include <algorithm>

const int N = 350 + 5;
const int M = 120 + 5;

int n, m, score[N + 5], f[M + 5][M + 5][M + 5][M + 5], num[5];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &score[i]);
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        num[tmp]++;
    }
    f[0][0][0][0] = score[1];
    for (int i = 0; i <= num[1]; i++)
        for (int j = 0; j <= num[2]; j++)
            for (int k = 0; k <= num[3]; k++)
                for (int l = 0; l <= num[4]; l++)
                {
                    int dis = i + j * 2 + k * 3 + l * 4 + 1;
                    if (i)
                        f[i][j][k][l] = std::max(f[i][j][k][l], f[i - 1][j][k][l] + score[dis]);
                    if (j)
                        f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j - 1][k][l] + score[dis]);
                    if (k)
                        f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j][k - 1][l] + score[dis]);
                    if (l)
                        f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j][k][l - 1] + score[dis]);
                }
    printf("%d", f[num[1]][num[2]][num[3]][num[4]]);
    return 0;
}