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

int n;
double tot, x, y, sum, a[N];

bool cmp(double a, double b) { return a > b; }

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        sum += a[i] = read();
    std::sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        tot += a[i];
        double nowx = i * 100.0 / n;
        double nowy = tot * 100.0 / sum;
        if (nowy - nowx > y - x)
            x = nowx, y = nowy;
    }
    return printf("%.2f\n%.2f", x, y), 0;
}