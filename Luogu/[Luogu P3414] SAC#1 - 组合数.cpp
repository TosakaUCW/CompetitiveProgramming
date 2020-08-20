#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef unsigned long long llu;

const llu P = 6662333;

llu n;

llu read()
{
    llu x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

llu pow(llu x, llu k)
{
    llu res = 1;
    for (x %= P; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

signed main()
{
    n = read();
    printf("%llu", pow(2, n - 1));
    return 0;
}