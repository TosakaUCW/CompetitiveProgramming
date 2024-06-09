#include <stdio.h>
#include <algorithm>
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

const int N = 1e6 + 5;

int n, m, ans, f, val;
int a[N], b[N];
bool buk[2][N];

void get()
{
    int p = 0, q = 0;
    for (int i = 2; i <= n; ++i)
        if (a[i] ^ a[1])
        {
            p = i - 1;
            break;
        }
    for (int i = n; i >= 1; --i)
    {
        q++;
        if (a[i] ^ a[1])
            break;
    }
    val = std::min(p, q);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), buk[0][a[i]] = 1;
    for (int i = 1; i <= m; i++)
        b[i] = read(), buk[1][b[i]] = 1;
    if (buk[1][0] and !buk[0][0] or buk[1][1] and !buk[0][1])
        return puts("-1"), 0;
    get(), f = a[1];
    for (int i = 1; i <= m; i++)
        if (f ^ b[i])
            f = b[i], ans += val, val = 1;
    printf("%d", ans + m);
    return 0;
}