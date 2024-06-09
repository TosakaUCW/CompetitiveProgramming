#include <stdio.h>
#include <algorithm>
#include <memory.h>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, L, R;
int a[N], b[N], c[N];

void solve()
{
    memset(c, 0, sizeof c);
    n = read(), L = read(), R = read();
    for (int i = 1; i <= L; i++)
        a[i] = read();
    for (int i = 1; i <= R; i++)
        b[i] = read();
    if (L > R)
    {
        swap(L, R);
        for (int i = 1; i <= n; i++)
            swap(a[i], b[i]);
    }
    int ans = (R - L) >> 1, cnt = 0;
    for (int i = 1; i <= R; i++)
        c[b[i]]++;
    for (int i = 1; i <= L; i++)
        if (c[a[i]])
            --c[a[i]];
        else
            ans++, cnt++;
    for (int i = 1; i <= n; i++)
        if (c[i] & 1)
            if (cnt)
                --cnt;
            else
                ans++, cnt++;
    printf("%d", ans);
}

int main()
{
    for (int T = read(); T--; solve(), puts(""))
        ;
    return 0;
}
