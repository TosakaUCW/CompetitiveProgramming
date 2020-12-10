#include <stdio.h>

double f[5][5][5][5][5][5][5][5][5];
int g[10];
char a[10][5], ch;

int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 4; j >= 1; j--)
            scanf("%s", &ch), a[i][j] = ch;
    f[0][0][0][0][0][0][0][0][0] = 1;
    for (g[1] = 0; g[1] <= 4; g[1]++)
        for (g[2] = 0; g[2] <= 4; g[2]++)
            for (g[3] = 0; g[3] <= 4; g[3]++)
                for (g[4] = 0; g[4] <= 4; g[4]++)
                    for (g[5] = 0; g[5] <= 4; g[5]++)
                        for (g[6] = 0; g[6] <= 4; g[6]++)
                            for (g[7] = 0; g[7] <= 4; g[7]++)
                                for (g[8] = 0; g[8] <= 4; g[8]++)
                                    for (g[9] = 0; g[9] <= 4; g[9]++)
                                        if (f[g[1]][g[2]][g[3]][g[4]][g[5]][g[6]][g[7]][g[8]][g[9]])
                                        {
                                            double tmp = f[g[1]][g[2]][g[3]][g[4]][g[5]][g[6]][g[7]][g[8]][g[9]];
                                            int cnt = 0;
                                            for (int i = 1; i <= 9; i++)
                                                for (int j = i + 1; j <= 9; j++)
                                                    if (g[i] + 1 <= 4 and g[j] + 1 <= 4 and a[i][g[i] + 1] == a[j][g[j] + 1])
                                                        cnt++;
                                            if (cnt > 0)
                                                for (int i = 1; i <= 9; i++)
                                                    for (int j = i + 1; j <= 9; j++)
                                                        if (g[i] + 1 <= 4 and g[j] + 1 <= 4 and a[i][g[i] + 1] == a[j][g[j] + 1])
                                                        {
                                                            g[i]++, g[j]++;
                                                            f[g[1]][g[2]][g[3]][g[4]][g[5]][g[6]][g[7]][g[8]][g[9]] += tmp / cnt;
                                                            g[i]--, g[j]--;
                                                        }
                                        }
    return printf("%.6lf", f[4][4][4][4][4][4][4][4][4]), 0;
}