#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 1e3 + 5;

ll n, ans;
ll a[N], f[N][2];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        f[i][1] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i][1] = std::max(f[i][1], f[j][0] + 1);
            else if (a[j] > a[i])
                f[i][0] = std::max(f[i][0], f[j][1] + 1);
    }
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, std::max(f[i][0], f[i][1]));
    printf("%lld", ans);
    return 0;
}