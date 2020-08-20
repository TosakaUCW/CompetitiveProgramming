#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 6;
const int P = 1e4;

int n, f[N][5];

int main()
{
    scanf("%d", &n);
    f[1][0] = f[1][3] = 1;
    for (int i = 2; i <= n; i++)
    {
        (f[i][0] = f[i - 1][3]) %= P;
        (f[i][1] = f[i - 1][0] + f[i - 1][2]) %= P;
        (f[i][2] = f[i - 1][0] + f[i - 1][1]) %= P;
        (f[i][3] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2] + f[i - 1][3]) %= P;
    }
    printf("%d", f[n][3]);
    return 0;
}