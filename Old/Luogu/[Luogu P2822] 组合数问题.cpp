#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e3;
const int M = 2e3;

int T, P;
int C[N + 5][M + 5], s[N + 5][M + 5];

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
    T = read(), P = read();
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (C[i][j] == 0);
        }
        s[i][i + 1] = s[i][i];
    }
    while (T--)
    {
        int n = read(), m = read();
        if (m > n)
            m = n;
        printf("%d\n", s[n][m]);
    }
    return 0;
}