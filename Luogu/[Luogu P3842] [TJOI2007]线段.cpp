#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 2e4 + 5;

int n;
int L[N], R[N];
int f[N][2];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &L[i], &R[i]);
    f[1][0] = R[1] * 2 - L[1] - 1;
    f[1][1] = R[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = std::min(f[i - 1][0] + abs(R[i] - L[i - 1]), f[i - 1][1] + abs(R[i - 1] - R[i])) + R[i] - L[i] + 1;
        f[i][1] = std::min(f[i - 1][0] + abs(L[i - 1] - L[i]), f[i - 1][1] + abs(R[i - 1] - L[i])) + R[i] - L[i] + 1;
    }
    printf("%d", std::min(f[n][0] + n - L[n], f[n][1] + n - R[n]));
    return 0;
}