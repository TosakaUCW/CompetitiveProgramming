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

const int N = 3e5 + 5;

int n, k, ans;
int a[N];

int main()
{
    freopen("telefoni.in", "r", stdin), freopen("telefoni.out", "w", stdout);
    n = read(), k = read();
    for (int i = 1, x = 0, sum = 0; i <= n; i++)
    {
        x = a[i] = read(), sum += x;
        if (i > k)
            sum -= a[i - k];
        if (i >= k and sum == 0)
            ans++, a[i] = 1, sum++;
    }
    return printf("%d", ans), 0;
}