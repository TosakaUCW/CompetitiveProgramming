#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

#define count(x) __builtin_popcount(x)

const int N = 100 + 5;

int n, m, ans;
int a[N];
int sta[N], sit[N], num_sta;
int f[3][N][N];

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
    n = read(), m = read();
    char ch;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> ch, a[i] = (a[i] << 1) + (ch == 'P');
    for (int i = 0; i < (1 << m); i++)
        if (!(i & (i >> 1)) and !(i & (i << 1)) and !(i & (i << 2)) and !(i & (i >> 2)))
            sta[++num_sta] = i, sit[num_sta] = count(i);

    for (int i = 1; i <= num_sta; i++)
        if ((sta[i] | a[1]) == a[1])
            f[1][i][0] = sit[i];

    for (int i = 1; i <= num_sta; i++)
        for (int j = 1; j <= num_sta; j++)
            if ((sta[i] | a[1]) == a[1] and (sta[j] | a[2]) == a[2] and !(sta[i] & sta[j]))
                f[2][j][i] = sit[i] + sit[j];

    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= num_sta; j++)
        {
            if ((sta[j] | a[i]) != a[i])
                continue;
            for (int k = 1; k <= num_sta; k++)
            {
                if ((sta[k] | a[i - 1]) != a[i - 1] or (sta[j] & sta[k]))
                    continue;
                for (int l = 1; l <= num_sta; l++)
                    if ((sta[l] | a[i - 2]) == a[i - 2] and !(sta[j] & sta[l]) && !(sta[k] & sta[l]))
                        f[i % 3][j][k] = std::max(f[i % 3][j][k], f[(i - 1) % 3][k][l] + sit[j]);
            }
        }

    for (int i = 1; i <= num_sta; i++)
        for (int j = 1; j <= num_sta; j++)
            ans = std::max(ans, f[n % 3][i][j]);
    printf("%d", ans);
    return 0;
}