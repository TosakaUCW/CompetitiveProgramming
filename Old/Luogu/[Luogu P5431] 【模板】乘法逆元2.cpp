#include <stdio.h>
#include <algorithm>
#include <string>

typedef long long ll;

const ll N = 5e6 + 5;

ll n, k, P, ans;
ll a[N], pre[N], suf[N], pred;

namespace io
{
    const int SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT;
    char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
    int f, qr;

#define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)

    inline void flush()
    {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    inline void putc(char x)
    {
        *oS++ = x;
        if (oS == oT)
            flush();
    }

    template <class I>
    inline void read(I &x)
    {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc())
            if (c == '-')
                f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc())
            x = x * 10 + (c & 15);
        x = f == -1 ? -x : x;
    }

    template <class I>
    inline void print(I x)
    {
        if (!x)
            putc('0');
        if (x < 0)
            putc('-'), x = -x;
        while (x)
            qu[++qr] = x % 10 + '0', x /= 10;
        while (qr)
            putc(qu[qr--]);
    }

    struct Flusher_
    {
        ~Flusher_() { flush(); }
    } io_flusher_;
} // namespace io
using io ::print;
using io ::putc;
using io ::read;

ll pow(ll x, ll k)
{
    ll res = 1;
    x %= P;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

signed main()
{
    read(n), read(P), read(k);
    for (ll i = 1; i <= n; i++)
        read(a[i]);
    pre[0] = suf[n + 1] = pred = 1;
    for (ll i = 1; i <= n; i++)
    {
        pred = pred * a[i] % P;
        pre[i] = pre[i - 1] * a[i] % P;
        suf[n - i + 1] = suf[n - i + 2] * a[n - i + 1] % P;
    }
    pred = pow(pred, P - 2);
    for (ll i = 1, kk = k; i <= n; i++, kk = kk * k % P)
        ans = (ans + ((pred * kk) % P) * ((pre[i - 1] * suf[i + 1]) % P)) % P;
    print(ans);
    return 0;
}