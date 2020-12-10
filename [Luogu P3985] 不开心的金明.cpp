#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int M = 3e5 + 5;

int n, m, min, max, ans;
int wei[N], val[N], f[M];

bool cmp(int a, int b) { return a > b; }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &wei[i], &val[i]);
        min = i == 1 ? wei[i] : std::min(min, wei[i]);
        max = std::max(max, wei[i]);
    }
    if (min <= 300)
    {
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= wei[i]; j--)
                f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
        printf("%d", f[m]);
    }
    else
    {
        std::sort(val + 1, val + 1 + n, cmp);
        for (int i = 1; i <= m / max; i++)
            ans += val[i];
        printf("%d", ans);
    }
    return 0;
}