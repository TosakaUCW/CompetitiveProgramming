#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 3e7;
const int P = 19930726;

ll n, k, p[N + 5], cnt[N + 5];
char s[N + 5], str[N + 5];

void Manacher()
{
    str[0] = str[1] = '#';
    int n = strlen(s);
    Rep(i, 1, n)
    {
        str[2 * i] = s[i - 1];
        str[2 * i + 1] = '#';
    }
    n = 2 * n + 2;
    int mid = 1, mx = 1;
    p[1] = 1;
    Rep(i, 2, n - 1)
    {
        if (i < mx)
            p[i] = std::min(p[2 * mid - i], p[mid] + mid - i);
        else
            p[i] = 1;
        while (str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if (mx < i + p[i])
        {
            mx = i + p[i];
            mid = i;
        }
        if ((p[i] - 1) % 2)
            cnt[p[i] - 1]++;
    }
}

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

void solve()
{
    ll sum = 0, ans = 1;
    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 0)
            continue;
        sum += cnt[i];
        if (k >= sum)
        {
            ans = (ans * pow(i, sum)) % P;
            k -= sum;
        }
        else
        {
            ans = (ans * pow(i, k)) % P;
            k -= sum;
            break;
        }
    }
    if (k > 0)
        ans = -1;
    printf("%lld", ans);
}

int main()
{
    scanf("%lld%lld", &n, &k);
    scanf("%s", s);
    Manacher();
    solve();
    return 0;
}