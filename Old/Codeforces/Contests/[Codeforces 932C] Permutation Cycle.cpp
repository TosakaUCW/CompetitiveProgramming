#include <stdio.h>
#include <algorithm>
#include <memory.h>

int n, a, b;

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
    n = read(), a = read(), b = read();
    for (int i = 0; i <= (n / a); i++)
        if ((n - a * i) % b == 0)
        {
            int x = 1;
            for (int j = 0; j < i; j++)
            {
                for (int i = x + 1; i < x + a; i++)
                    printf("%d ", i);
                printf("%d ", x), x += a;
            }
            for (int j = 0; j < (n - a * i) / b; j++)
            {
                for (int i = x + 1; i < x + b; i++)
                    printf("%d ", i);
                printf("%d ", x), x += b;
            }
            return 0;
        }
    return puts("-1"), 0;
}