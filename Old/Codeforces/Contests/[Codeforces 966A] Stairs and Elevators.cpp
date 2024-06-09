#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int INF = 2147483646;

int n, m, an, bn, v, q;
int a[N], b[N];
int x1, y1, x2, y2;

// a 楼梯
// b 电梯

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
    n = read(), m = read(), an = read(), bn = read(), v = read();
    for (int i = 1; i <= an; i++)
        a[i] = read();
    for (int i = 1; i <= bn; i++)
        b[i] = read();
    for (int q = read(), res, x1, y1, x2, y2; q--;)
    {
        res = INF, x1 = read(), y1 = read(), x2 = read(), y2 = read();
        if (x1 == x2)
        {
            printf("%d\n", abs(y1 - y2));
            continue;
        }
        int k = std::lower_bound(a + 1, a + 1 + an, y1) - a;
        if (k <= an)
            res = std::min(res, abs(a[k] - y1) + abs(x2 - x1) + abs(a[k] - y2));
        if (k > 1)
            res = std::min(res, abs(a[k - 1] - y1) + abs(x2 - x1) + abs(a[k - 1] - y2));
        k = std::lower_bound(b + 1, b + 1 + bn, y1) - b;
        if (k <= bn)
            res = std::min(res, abs(b[k] - y1) + (abs(x2 - x1) - 1) / v + 1 + abs(b[k] - y2));
        if (k > 1)
            res = std::min(res, abs(b[k - 1] - y1) + (abs(x2 - x1) - 1) / v + 1 + abs(b[k - 1] - y2));
        printf("%d\n", res);
    }
    return 0;
}