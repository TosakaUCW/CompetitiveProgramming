#include <stdio.h>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e5;

ll n, m, ans;
ll a[N + 5];

int main()
{
    scanf("%lld%lld", &n, &m);
    Rep(i, 1, n)
        scanf("%lld", &a[i]);
    while (true)
    {
        ll x = 0, y = 0;
        Rep(i, 1, n)
        {
            if (x + a[i] <= m)
            {
                x += a[i];
                y++;
            }
        }
        if (!x)
            break;
        ans += m / x * y;
        m %= x;
    }
    printf("%lld", ans);
    return 0;
}