#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 15e4 + 5;
const ll M = 3e2 + 5;
const ll INF = 1LL << 60;

ll n, m, d, ans = INF, sum;
ll a[N], b[N], t[N];
ll f[2][N];
ll Q[N];

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

signed main()
{
    n = read(), m = read(), d = read();
    for (ll i = 1; i <= m; i++)
        a[i] = read(), b[i] = read(), t[i] = read();
    for (ll i = 1, k = 0; i <= m; i++, k ^= 1)
    {
        sum += b[i];
        ll len = (t[i] - t[i - 1]) * d, head = 1, tail = 0;
        for (ll j = 1; j <= n; j++)
        {
            while (head <= tail and Q[head] < j - len)
                ++head;
            while (head <= tail and f[k][Q[tail]] > f[k][j])
                --tail;
            Q[++tail] = j;
            f[k ^ 1][j] = f[k][Q[head]] + abs(a[i] - j);
        }
        head = 1, tail = 0;
        for (ll j = n; j >= 1; j--)
        {
            while (head <= tail and Q[head] > j + len)
                ++head;
            while (head <= tail and f[k][Q[tail]] > f[k][j])
                --tail;
            Q[++tail] = j;
            f[k ^ 1][j] = std::min(f[k ^ 1][j], f[k][Q[head]] + abs(a[i] - j));
        }
    }
    for (ll i = 1; i <= n; i++)
        ans = std::min(ans, f[m % 2][i]);
    printf("%lld", sum - ans);
    return 0;
}