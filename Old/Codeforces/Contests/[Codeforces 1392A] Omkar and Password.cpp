#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;

int n, a[N];

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
        int n = read();
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (a[i] != a[i - 1] and i != 1)
                flag = true;
        }
        printf("%d\n", flag ? 1 : n);
    }
    return 0;
}