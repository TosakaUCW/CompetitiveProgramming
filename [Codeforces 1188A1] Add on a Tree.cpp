#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, d[N];

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
        d[read()]++, d[read()]++;
    for (int i = 1; i <= n; i++)
        if (d[i] == 2)
            return puts("NO"), 0;
    return puts("YES"), 0;
}