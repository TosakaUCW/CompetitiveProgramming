#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, x;
int a[N], b[N];

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
    for (int T = read(); T--;)
    {
        bool flag = true;
        n = read(), x = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            b[i] = read();
        std::sort(a + 1, a + 1 + n);
        std::sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n and flag; i++)
            if (a[i] + b[n - i + 1] > x)
                flag = false;
        puts(flag ? "Yes" : "No");
    }
    return 0;
}