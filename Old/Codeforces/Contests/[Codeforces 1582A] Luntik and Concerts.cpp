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

void solve()
{
    int a = read(), b = read(), c = read();
    printf("%lld\n", (a + 2 * b + 3 * c) % 2);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
