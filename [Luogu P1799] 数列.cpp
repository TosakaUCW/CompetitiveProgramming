#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;

int n, ans;
int f[2][N];

struct Node
{
    int val, tar, idx;
} a[N];

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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].val = read(), a[i].tar = a[i].val, a[i].idx = i;
    for (int i = 1, k = 1; i <= n; i++, k ^= 1)
    {
        f[k][0] = f[k ^ 1][0] + (a[i].idx == a[i].tar);
        for (int j = 1; j <= i; j++)
            f[k][j] = std::max(f[k ^ 1][j - 1], f[k ^ 1][j] + (a[i].idx - j == a[i].tar));
    }
    for (int i = 0; i <= n; i++)
        ans = std::max(ans, f[n % 2][i]);
    printf("%d", ans);
    return 0;
}