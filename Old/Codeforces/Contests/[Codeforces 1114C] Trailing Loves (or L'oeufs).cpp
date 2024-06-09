#include <stdio.h>

typedef long long ll;

const int N = 2e6 + 5;
const ll INF = 1LL << 60;

int cnt;
ll n, k, p[N], c[N], ans = INF;

int main()
{
    scanf("%I64d%I64d", &n, &k);
    for (ll i = 2; i * i <= k; ++i)
        if (k % i == 0)
        {
            p[++cnt] = i;
            c[cnt] = 0;
            while (k % i == 0)
            {
                ++c[cnt];
                k /= i;
            }
        }
    if (k > 1)
    {
        p[++cnt] = k;
        c[cnt] = 1;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        ll t = 0, tmp = n;
        while (tmp)
            t += tmp /= p[i];
        t /= c[i];
        if (t < ans)
            ans = t;
    }
    printf("%I64d", ans);
    return 0;
}