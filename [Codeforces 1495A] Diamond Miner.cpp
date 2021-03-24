#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n;
double ans;
int x[N], y[N];

int main()
{
    for (int T = read(); T--;)
    {
        n = read(), ans = 0;
        memset(x, 0, sizeof x), memset(y, 0, sizeof y);
        for (int i = 1, a, b; i <= n * 2; i++)
        {
            a = read(), b = read();
            if (!a)
                y[++y[0]] = abs(b);
            else
                x[++x[0]] = abs(a);
        }
        std::sort(x + 1, x + 1 + x[0]), std::sort(y + 1, y + 1 + y[0]);
        for (int i = 1; i <= n; i++)
            ans += 1.0 * sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
        printf("%.15f\n", ans);
    }
    return 0;
}