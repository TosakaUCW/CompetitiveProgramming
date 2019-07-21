#include <stdio.h>
#include <algorithm>

typedef unsigned __int128 ll;

const int N = 1e6 + 5;

ll n, m;
ll a[N], b[N];
ll bit[N];

void add(int i, ll x)
{
    for (; i <= m; i += i & -i)
        bit[i] += x;
}

ll query(int i)
{
    ll r = 0;
    for (; i; i -= i & -i)
        r += bit[i];
    return r;
}

ll query(int l, int r)
{
    return query(r) - query(l - 1);
}

void print(ll n)
{
    if (n < 10)
        return (void)putchar(n + '0');
    print(n / 10);
    putchar(n % 10 + '0');
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(a[i], i);
        ans += 1LL * (n - i + 1) * query(a[i] + 1, m);
    }
    print(ans);
    return 0;
}