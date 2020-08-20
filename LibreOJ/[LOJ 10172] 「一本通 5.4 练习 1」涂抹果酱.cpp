#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

typedef long long ll;

const ll N = 1e4 + 1;
const ll M = 5;
const ll P = 1e6;

ll n, m, k;
ll sta[N], num_sta, k_sta, k_idx;
ll f[N][N];

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

bool judge(ll x)
{
    for (ll i = 1, tmp = -1; i <= m; i++, tmp = x % 3, x /= 3)
        if (tmp == x % 3)
            return false;
    return true;
}

bool judge(ll x, ll y)
{
    for (ll i = 1; i <= m; i++, x /= 3, y /= 3)
        if (x % 3 == y % 3)
            return false;
    return true;
}

signed main()
{
    n = read(), m = read(), k = read();
    for (ll i = 0, k = pow(3, m); i < k; i++)
        if (judge(i))
            sta[++num_sta] = i;
    for (ll i = 1, x; i <= m; i++)
        x = read(), k_sta = k_sta * 3 + x - 1;
    if (!judge(k_sta))
    {
        puts("0");
        return 0;
    }
    for (ll i = 1; i <= num_sta; i++)
        if (sta[i] == k_sta)
        {
            k_idx = i;
            break;
        }
    for (ll i = 1; i <= n; i++)
        if (i == k)
        {
            if (i == 1)
                f[i][k_idx] = 1;
            else
                for (ll j = 1; j <= num_sta; j++)
                    if (judge(sta[k_idx], sta[j]))
                        f[i][k_idx] = (f[i][k_idx] + f[i - 1][j]) % P;
        }
        else
            for (ll j = 1; j <= num_sta; j++)
                if (i == 1)
                    f[i][j] = 1;
                else
                    for (ll k = 1; k <= num_sta; k++)
                        if (judge(sta[j], sta[k]))
                            f[i][j] = (f[i][j] + f[i - 1][k]) % P;
    ll ans = 0;
    for (ll i = 1; i <= num_sta; i++)
        ans = (ans + f[n][i]) % P;
    printf("%lld", ans);
    return 0;
}