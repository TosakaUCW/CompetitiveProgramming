#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int a, b, c, d;

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
    a = read(), b = read(), c = read(), d = read();
    if (a == 0 and b == 0)
    {
        puts("0");
        return 0;
    }
    if (a == b)
    {
        printf("%d", std::min(c, d + d));
        return 0;
    }
    if (a == 0 or b == 0)
    {
        printf("%d", d);
        return 0;
    }
    printf("%d", std::min(c + d, d + d));
    return 0;
}