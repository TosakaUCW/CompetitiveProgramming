#include <stdio.h>

#define int long long

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

signed main()
{
    for (int T = read(); T--;)
    {
        int x = 0, a = read(), b = read(), c = read(), d = read();
        if (b * c < a)
            puts("-1");
        else if (a % (b * d))
            x = a / (b * d);
        else
            x = a / (b * d) - 1;
        printf("%lld\n", (x + 1) * a - d * b * (x + 1) * x / 2);
    }
    return 0;
}