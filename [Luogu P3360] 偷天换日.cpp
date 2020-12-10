#include <stdio.h>
#include <algorithm>

typedef long long ll;

#define ls (u << 1)
#define rs (u << 1 | 1)

const ll K = 30 + 5;
const ll N = 1e3 + 5;
const ll M = 3e3 + 5;

ll m;
ll val[N], wei[N];
ll f[N][M];

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

void dfs(ll u)
{
    ll cost = read(), num = read();
    cost <<= 1;
    if (!num)
    {
        dfs(ls), dfs(rs);
        for (ll i = cost; i <= m; i++)
            for (ll j = 0; i - cost - j >= 0; j++)
                f[u][i] = std::max(f[u][i], f[ls][j] + f[rs][i - cost - j]);
    }
    else
    {
        for (ll i = 1; i <= num; i++)
            val[i] = read(), wei[i] = read();
        for (ll i = 1; i <= num; i++)
            for (ll j = m; j - wei[i] >= cost; j--)
                f[u][j] = std::max(f[u][j], f[u][j - wei[i]] + val[i]);
    }
}

signed main()
{
    m = read(), m--;
    dfs(1);
    printf("%lld", f[1][m]);
    return 0;
}