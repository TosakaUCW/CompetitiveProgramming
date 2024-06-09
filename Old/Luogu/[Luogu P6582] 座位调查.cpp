#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

typedef long long ll;

const ll N = 1e3 + 5;
const ll dx[] = {0, 0, 1, -1};
const ll dy[] = {1, -1, 0, 0};
const ll P = 998244353;

ll n, m, k;
ll a[N][N];
ll cnt[N][N];
bool vis[N][N];
ll flag_0, flag_1, flag_3;
ll ans, tot;

ll pow(ll x, ll k)
{
    ll res = 1;
    x %= P;
    while (k > 0)
    {
        if (k & 1)
            res = (res * x) % P;
        x = (x * x) % P;
        k >>= 1;
    }
    return res;
}

void dfs(ll x, ll y)
{
    for (ll i = 0; i < 4; i++)
    {
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if (vis[xx][yy] or 1 > xx or xx > n or 1 > yy or yy > m or !a[xx][yy] or flag_3)
            continue;
        if (cnt[xx][yy] == 0)
            flag_0++;
        else if (cnt[xx][yy] == 1)
            flag_1++;
        else if (cnt[xx][yy] >= 3)
        {
            flag_3++;
            return;
        }
        tot++, vis[xx][yy] = true, dfs(xx, yy);
    }
}

int main()
{
    std::cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            char ch;
            std::cin >> ch;
            a[i][j] = (ch == 'O');
        }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            if (a[i][j])
                cnt[i][j] = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];

    for (ll x = 1; x <= n; x++)
        for (ll y = 1; y <= m; y++)
        {
            flag_0 = 0;
            flag_1 = 0;
            flag_3 = 0;
            tot = 0;
            if (vis[x][y] or !a[x][y] or cnt[x][y] >= 3)
                continue;
            if (cnt[x][y] == 0)
                flag_0++;
            else if (cnt[x][y] == 1)
                flag_1++;
            tot++, vis[x][y] = true, dfs(x, y);
            if ((flag_1 == 2 or flag_0 == 1) and !flag_3)
            {
#ifndef ONLINE_JUDGE
                printf("ans:%lld\nk * pow(k - 1, tot - 1):%lld\n", ans, k * pow(k - 1, tot - 1));
#endif // !ONLINE_JUDGE
                if (ans == 0)
                    ans = 1;
                // (ans *= k * pow(k - 1, tot - 1)) %= P;
                ll tmp = (k * pow(k - 1, tot - 1)) % P;
                ans = (ans * tmp) % P;
            }
            else
            {
                puts("0");
                return 0;
            }
        }

#ifndef ONLINE_JUDGE
    puts("a[][]:");
    for (ll i = 1; i <= n; i++, puts(""))
        for (ll j = 1; j <= m; j++)
            printf("%lld ", a[i][j]);
    puts("cnt[][]:");
    for (ll i = 1; i <= n; i++, puts(""))
        for (ll j = 1; j <= m; j++)
            printf("%lld ", cnt[i][j]);
    puts("vis[][]:");
    for (ll i = 1; i <= n; i++, puts(""))
        for (ll j = 1; j <= m; j++)
            printf("%lld ", vis[i][j] == 1);
    printf("ans:");
#endif // !ONLINE_JUDGE

    printf("%lld", (ans + P) % P);
    return 0;
}