#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 2e5 + 5;

ll m, n, k;
ll ans, emote[N];

bool cmp(ll a, ll b) { return a > b; }

int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &emote[i]);
    std::sort(emote + 1, emote + 1 + n, cmp);
    if (n == 1)
    {
        printf("%I64d", emote[1] * (std::min(m, k)));
        return 0;
    }
    ans = m / (k + 1) * (emote[1] * k + emote[2]) + (m % (k + 1)) * emote[1];
    printf("%I64d", ans);
    return 0;
}