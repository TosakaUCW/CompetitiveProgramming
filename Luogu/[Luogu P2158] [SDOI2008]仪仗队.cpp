#include <stdio.h>
#include <algorithm>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 4e4;

ll n, ans, phi[N + 5];

int main()
{
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("%lld", ans);
        return 0;
    }
    Rep(i, 1, n)
        phi[i] = i;
    Rep(i, 2, n)
    {
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] = phi[j] / i * (i - 1);
    }
    n--;
    Rep(i, 2, n)
        ans += 2 * phi[i];
    ans += 3;
    printf("%lld", ans);
    return 0;
}