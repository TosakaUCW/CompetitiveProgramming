#include <stdio.h>

typedef long long ll;

const ll N = 18 + 2;
const ll M = 1 << N;

ll n, q;
ll sum[M << 2];
bool rev[N];

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

#define ls (p << 1)
#define rs (p << 1 | 1)
#define lson (p << 1 | rev[depth])
#define rson (p << 1 | rev[depth] ^ 1)

void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        sum[p] = read();
        return;
    }
    ll mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    sum[p] = sum[ls] + sum[rs];
}

void modify(ll p, ll l, ll r, ll depth, ll k, ll val)
{
    if (l == r)
    {
        sum[p] = val;
        return;
    }
    ll mid = l + r >> 1;
    if (k <= mid)
        modify(lson, l, mid, depth - 1, k, val);
    else
        modify(rson, mid + 1, r, depth - 1, k, val);
    sum[p] = sum[ls] + sum[rs];
}

ll query(ll p, ll l, ll r, ll depth, ll x, ll y)
{
    if (x <= l and r <= y)
        return sum[p];
    ll mid = l + r >> 1, res = 0;
    if (x <= mid)
        res += query(lson, l, mid, depth - 1, x, y);
    if (mid + 1 <= y)
        res += query(rson, mid + 1, r, depth - 1, x, y);
    return res;
}

signed main()
{
    n = read(), q = read();
    build(1, 1, 1LL << n);
    for (ll opt, x, y; q--;)
    {
        opt = read();
        if (opt == 1)
            x = read(), y = read(), modify(1, 1, 1LL << n, n, x, y);
        else if (opt == 2)
            for (x = read(); ~x; x--)
                rev[x] ^= 1;
        else if (opt == 3)
            x = read(), rev[x + 1] ^= 1;
        else
            x = read(), y = read(), printf("%lld\n", query(1, 1, 1LL << n, n, x, y));
    }
    return 0;
}