#include <stdio.h>
#include <algorithm>

#define int long long

int a[5];

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
        a[1] = read(), a[2] = read(), a[3] = read(), a[4] = read();
        std::sort(a + 1, a + 5);
        if (a[1] == a[2] and a[2] == a[3] and a[3] == a[4])
            puts("1");
        else if (a[1] == a[2] and a[3] == a[4])
            puts("4");
        else if (a[1] + a[4] == a[2] + a[3])
            puts("8");
        else
            puts("0");
    }
    return 0;
}
