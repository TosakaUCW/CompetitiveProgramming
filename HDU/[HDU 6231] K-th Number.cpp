#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, k, m, a[N];

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

bool judge(int mid)
{
    int L = 1, R = 1, cnt = a[1] >= mid, res = 0;
    while (R <= n)
        if (cnt >= k)
            res += n - R + 1, cnt -= a[L++] >= mid;
        else
            cnt += a[++R] >= mid;
    return res >= m;
}

signed main()
{
    for (int T = read(); T--;)
    {
        n = read(), k = read(), m = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        int res = -1;
        for (int L = 1, R = 1e9, mid; L <= R;)
            if (judge(mid = (L + R) >> 1))
                res = mid, L = mid + 1;
            else
                R = mid - 1;
        printf("%lld\n", res);
    }
    return 0;
}