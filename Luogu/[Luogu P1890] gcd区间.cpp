#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string>

const int N = 1e5 + 5;

int n, m;
int st[N][25];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int query(int l, int r)
{
    int k = log2(r - l + 1);
    return std::__gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        st[i][0] = read();
    for (int j = 1; j <= 21; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = std::__gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while (m--)
    {
        int l, r;
        l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}