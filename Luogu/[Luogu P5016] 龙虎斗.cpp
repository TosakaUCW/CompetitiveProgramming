#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)
typedef long long ll;

const int N = 1e5;
const ll INF = 1LL << 62;
int n, m, p1, ans;
ll s1, s2;
ll c[N + 5];
ll sum, max = INF;

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
        scanf("%lld", &c[i]);
    scanf("%d%d%lld%lld", &m, &p1, &s1, &s2);
    c[p1] += s1;
    Rep(i, 1, n)
        sum += c[i] * (i - m);
    Rep(i, 1, n)
    {
        ll k = sum + (i - m) * s2;
        if (k < 0)
            k = -k;
        if (k < max)
        {
            max = k;
            ans = i;
        }
    }
    printf("%d", ans);
    return 0;
}