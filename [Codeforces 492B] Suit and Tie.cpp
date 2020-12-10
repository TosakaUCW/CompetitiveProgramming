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

int n, ans;
int a[N];

int main()
{
    n = read() * 2;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (; n; n -= 2)
        for (int i = 1; i <= n; i++)
            if (a[i] == a[n])
            {
                ans += n - i - 1;
                for (int j = i; j <= n - 1; j++)
                    std::swap(a[j], a[j + 1]);
                break;
            }
    return printf("%d", ans), 0;
}