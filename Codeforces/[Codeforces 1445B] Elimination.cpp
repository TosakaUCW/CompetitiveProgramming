#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

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
        int a = read(), b = read(), c = read(), d = read();
        printf("%d\n", std::max(a + b, c + d));
    }
    return 0;
}