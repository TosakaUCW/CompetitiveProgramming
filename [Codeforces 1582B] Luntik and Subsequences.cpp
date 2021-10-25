#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n;

void solve()
{
    n = read();
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (x == 0)
            b++;
        else if (x == 1)
            a++;
    }
    printf("%lld\n", a * (1LL << b));
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
