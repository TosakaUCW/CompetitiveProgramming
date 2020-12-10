#include <stdio.h>
#include <algorithm>
#include <memory.h>

int n, b, g, ans;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    b = read(), g = read(), n = read();
    for (int i = 0; i <= b; i++)
        for (int j = 0; j <= g; j++)
            if (i + j == n)
                ans++;
    return printf("%d", ans), 0;
}