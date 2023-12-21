#include <stdio.h>
#include <algorithm>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, d, p, ans;
int f[N];

signed main()
{
    n = read(), d = read(), p = read();
    for (int i = 1; i <= n; i++)
        f[i] = read();
    std::sort(f + 1, f + 1 + n, [](int a, int b)
              { return a > b; });
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += f[i];
    for (int i = 1; i <= n; i++)
    {
        int j = i, tot = 0;
        for (; j < i + d and j <= n; j++)
            tot += f[j];
        if (tot > p)
            sum += p - tot, i = j - 1;
        else
            break;
    }
    printf("%lld", sum);
    return 0;
}