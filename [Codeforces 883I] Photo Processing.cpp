#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e5 + 5;

int n, k;
int a[N], f[N];

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

bool judge(int mid)
{
    int x = 0;
    for (int i = k; i <= n; f[i++] = x)
        if (a[i] - a[f[i - k] + 1] <= mid)
            x = i;
    return f[n] == n;
}

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    int res = 0;
    for (int L = 0, R = a[n] - a[1], mid; L <= R;)
        if (judge(mid = (L + R) >> 1))
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    return printf("%d", res), 0;
}