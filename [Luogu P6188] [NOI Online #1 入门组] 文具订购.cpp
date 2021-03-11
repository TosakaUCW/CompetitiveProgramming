#include <stdio.h>
#include <algorithm>

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
    int n = read();
    if (!n)
        return puts("0 0 0"), 0;
    for (int i = n / 14; ~i; i--)
        for (int j = i; j <= n / 4; j++)
            for (int k = i; k <= n / 3; k++)
                if (i * 7 + j * 4 + k * 3 == n)
                    return printf("%d %d %d", i, j, k), 0;
    return puts("-1"), 0;
}