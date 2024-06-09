#include <stdio.h>
#include <algorithm>

const int N = 50 + 5;
const int M = 4e2 + 5;

int n, VOL, MAS;
int vol[N], mas[N], cal[N];
int f[M][M];

int main()
{
    scanf("%d%d%d", &VOL, &MAS, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &vol[i], &mas[i], &cal[i]);
    for (int i = 1; i <= n; i++)
        for (int j = VOL; j >= vol[i]; j--)
            for (int k = MAS; k >= mas[i]; k--)
                f[j][k] = std::max(f[j][k], f[j - vol[i]][k - mas[i]] + cal[i]);
    printf("%d", f[VOL][MAS]);
    return 0;
}