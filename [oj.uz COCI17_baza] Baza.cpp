#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e3 + 5;

int n, m;
int a[N][N], b[N];

int main()
{
    freopen("baza.in", "r", stdin), freopen("baza.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int q = read(); q--;)
    {
        for (int i = 1; i <= m; i++)
            b[i] = read();
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = 1; j <= m; j++)
                if (b[j] ^ -1)
                    flag &= b[j] == a[i][j];
            res += flag;
        }
        printf("%d\n", res);
    }
    return 0;
}