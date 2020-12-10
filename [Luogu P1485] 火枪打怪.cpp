#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

typedef long long ll;

const ll N = 5e5 + 5;

ll n, k;
ll hp[N], num[N];

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

bool judge(ll p)
{
    ll tot = 0;
    ll len = sqrt(p);
    memset(num, 0, sizeof num);
    ll cnt = 0, i = 0, i2 = 0;
    for (ll j = n; j >= 1; j--)
    {
        if (num[j + 1])
        {
            cnt += num[j + 1];
            i += num[j + 1] * (j + 1);
            i2 += num[j + 1] * (j + 1) * (j + 1);
        }
        if (j + len + 1 <= n and num[j + len + 1])
        {
            cnt -= num[j + len + 1];
            i -= num[j + len + 1] * (j + len + 1);
            i2 -= num[j + len + 1] * (j + len + 1) * (j + len + 1);
        }
        ll dam = cnt * p - j * j * cnt + 2LL * i * j - i2;
        if (dam <= hp[j])
        {
            num[j] = (hp[j] - dam) / p + 1;
            tot += num[j];
        }
        if (tot > k)
            return false;
    }
    return tot <= k;
}

signed main()
{
    ll L = 0, j = 0, res = 0;
    n = read(), k = read();
    for (ll i = 1; i <= n; i++)
        hp[i] = read(), j = std::max(j, hp[i]);
    j += n * n;
    while (L <= j)
    {
        ll mid = (L + j) / 2;
        if (judge(mid))
            res = mid, j = mid - 1;
        else
            L = mid + 1;
    }
    printf("%lld", res);
    return 0;
}