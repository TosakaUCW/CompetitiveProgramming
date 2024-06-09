#include <bits/stdc++.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e3 + 5;

int n, k;
int a[N];

bool judge(int x)
{
    for (int i = 1; i <= n; i++)
    {
        int rem = k;
        for (int j = i, p = x; j <= n; j++, p--)
        {
            if (a[j] >= p)
                return 1;
            if (rem < p - a[j])
                break;
            rem -= p - a[j];
        }
    }
    return 0;
}

void solve()
{
    n = read(), k = read();
    int L = 0, R = 2e8, ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    while (L <= R)
    {
        int mid = L + R >> 1;
        if (judge(mid))
            ans = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%d\n", std::max(ans, a[n]));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}