#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;

int n, ans = 1;
int c[N];
bool vis[N];

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
    n = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 2; i <= n; i++)
        if (c[i] == 1 and c[i - 1] == 0)
            ans++;
    return printf("%d", ans), 0;
}
/*
9
1 0 1 1 1 0 0 0 1

      x-1  x
*/