#include <stdio.h>
#include <algorithm>

#define abs(x) (x < 0 ? -x : x)

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m, ans;
int a[N], b[N];

int judge(int x, int res = 0)
{
    for (int i = 0, now = 0; i < n; i++)
    {
        while (now < m and b[now] < a[i] - x)
            now++;
        if (now < m and abs(b[now] - a[i]) <= x)
            res++, now++;
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cipele.in", "r", stdin);
    freopen("cipele.out", "w", stdout);
#endif // !ONLINE_JUDGE
    n = read(), m = read();
    for (int i = 0; i < n; i++)
        a[i] = read();
    for (int i = 0; i < m; i++)
        b[i] = read();
    std::sort(a, a + n), std::sort(b, b + m);
    for (int L = 0, R = 1e9, mid; L <= R;)
        if (judge(mid = (L + R) >> 1) == std::min(n, m))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    return printf("%d", ans), 0;
}