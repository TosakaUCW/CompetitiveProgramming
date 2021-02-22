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

const int N = 5e5 + 5;

int n;
int a[N];

int main()
{
    freopen("hindex.in", "r", stdin), freopen("hindex.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    for (int i = n; i >= 0; i--)
        if (a[i] < n - i + 1)
        {
            printf("%d", n - i);
            return 0;
        }
    return 0;
}