#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 5e5 + 5;
const ll INF = 1LL << 50;

ll n, d, m;
ll dis[N], val[N];
ll f[N], Q[N];

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

bool judge(ll g)
{
    memset(f, 0, sizeof f);
    ll head = 1, tail = 0, min = std::max(1LL, d - g), max = d + g;
    for (ll i = 1, j = 0; i <= n; i++)
    {
        for (; dis[j] + min <= dis[i]; j++)
        {
            while (head <= tail and f[j] > f[Q[tail]])
                tail--;
            Q[++tail] = j;
        }
        while (head <= tail and dis[Q[head]] + max < dis[i])
            head++;
        if (head <= tail)
            f[i] = f[Q[head]] + val[i];
        else
            f[i] = -INF;
        if (f[i] >= m)
            return true;
    }
    return false;
}

signed main()
{
    n = read(), d = read(), m = read();
    for (ll i = 1; i <= n; i++)
        dis[i] = read(), val[i] = read();
    ll L = 0, R = dis[n], res = -1;
    while (L <= R)
    {
        ll mid = L + R >> 1;
        if (judge(mid))
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%lld", res);
    return 0;
}