#include <stdio.h>
#include <algorithm>

#define int long long

int a[10], sum = 50;

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
    for (int i = 1; i <= 9; i++)
        a[i] = read(), sum += a[i];
    sum -= a[9] + a[8], sum += a[8] * 5;
    if (sum >= a[9])
        puts("AKIOI");
    else
        puts("AFO");
    return 0;
}