#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 50 + 5;
const ll M = 1e6 + 5;

ll m, n, ans;
ll f[M];

struct Node
{
    ll a, b, c;
    bool friend operator<(Node a, Node b) { return b.b * a.c < a.b * b.c; }
} a[N];

int main()
{
    scanf("%d%d", &m, &n);
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i].a);
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i].b);
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i].c);
    std::sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++)
        for (ll j = m; j >= a[i].c; j--)
            f[j] = std::max(f[j], f[j - a[i].c] + a[i].a - j * a[i].b);
    for (ll i = 0; i <= m; i++)
        ans = std::max(ans, f[i]);
    printf("%d", ans);
    return 0;
}