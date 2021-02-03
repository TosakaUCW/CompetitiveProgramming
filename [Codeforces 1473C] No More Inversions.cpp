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

const int N = 1e5 + 5;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    for (int T = read(); T--; puts(""))
    {
        int n = read(), k = read(), del = n - k;
        for (int i = 1; i <= k - 1 - del; i++)
            printf("%d ", i);
        for (int i = k; i >= k - del; i--)
            printf("%d ", i);
    }
    return 0;
}