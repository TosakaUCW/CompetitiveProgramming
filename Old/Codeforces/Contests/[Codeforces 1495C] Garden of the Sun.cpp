#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e2 + 5;

int n, m;
char a[N][N];

int main()
{
    for (int T = read(); T--;)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        for (int j = 1 + (m % 3 == 0), k; j <= m;)
        {
            for (int i = 1; i <= n; i++)
                a[i][j] = 'X';
            j += 3;
            if (j > m)
                break;
            k = 2;
            if (n == 1 or (a[2][j - 1] != 'X' and a[2][j - 2] != 'X'))
                k = 1;
            a[k][j - 1] = a[k][j - 2] = 'X';
        }
        for (int i = 1; i <= n; i++)
            puts(a[i] + 1);
    }
    return 0;
}