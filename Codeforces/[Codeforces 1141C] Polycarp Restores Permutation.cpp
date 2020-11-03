#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>

const int N = 2e5 + 5;

int n;
int a[N], c[N];
bool b[N];

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

int judge(int x)
{
    memset(b, false, sizeof b);
    a[1] = x, b[x] = true;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + c[i];
        if (a[i] < 1)
            return 2;
        if (a[i] > n)
            return 3;
        if (b[a[i]])
        {
            puts("-1");
            exit(0);
        }
        b[a[i]] = true;
    }
    return 1;
}

int main()
{
    n = read();
    for (int i = 2; i <= n; i++)
        c[i] = read();
    int L = 1, R = n, ans = -1;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (judge(mid) == 1)
        {
            ans = mid;
            break;
        }
        else if (judge(mid) == 2)
            L = mid + 1;
        else
            R = mid - 1;
    }
    if (ans == -1)
        puts("-1");
    else
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
    return 0;
}