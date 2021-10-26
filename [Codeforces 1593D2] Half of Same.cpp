#include <stdio.h>
#include <algorithm>
#include <mem.h>
#include <vector>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 100 + 5;

int n, ans;
int a[N];

bool judge(int k, int x)
{
    int res = 0;
    for (int i = x; i <= n; i++)
        if ((a[i] - a[x]) % k == 0)
            res++;
    return res >= n / 2;
}

void solve()
{
    n = read(), ans = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i + n / 2 - 1 <= n; i++)
        if (a[i] == a[i + n / 2 - 1])
            return puts("-1"), void();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int d = a[j] - a[i];
            for (int p = 1; p * p <= d; p++)
            {
                if (judge(p, i))
                    ans = std::max(ans, p);
                if (judge(d / p, i))
                    ans = std::max(ans, d / p);
            }
        }
    printf("%d\n", ans);
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}