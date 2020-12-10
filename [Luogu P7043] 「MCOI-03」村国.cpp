#include <stdio.h>
#include <algorithm>
#include <memory.h>

// #define int long long

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

typedef long long ll;

const int N = 2e6 + 1;
const int M = N << 1;

int max, x, y;
int n, a[N];
ll m;

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
    for (register int T = read(); T--; max = 0)
    {
        n = read(), scanf("%lld", &m);
        for (register int i = 1; i <= n; i++)
            if ((a[i] = read()) > max)
                max = a[i], x = i;
        max = 0, y = x;
        for (register int i = 1, u, v; i < n; i++)
        {
            u = read(), v = read();
            if (u == x and a[v] > max)
                max = a[v], y = v;
            else if (v == x and a[u] > max)
                max = a[u], y = u;
        }
        m -= a[x] - a[y];
        printf("%d\n", m < 0 ? x : (m & 1 ? max(x, y) : min(x, y)));
    }
    return 0;
}
