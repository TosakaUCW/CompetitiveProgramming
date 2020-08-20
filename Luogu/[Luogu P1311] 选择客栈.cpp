#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;
const int K = 50 + 5;

int n, p, ans;
int last[K], cnt[K], sum[K];

int main()
{
    scanf("%d%*d%d", &n, &p);
    for (int i = 1, color, price, now; i <= n; i++)
    {
        scanf("%d%d", &color, &price);
        if (price <= p)
            now = i;
        if (now >= last[color])
            sum[color] = cnt[color];
        last[color] = i;
        ans += sum[color];
        cnt[color]++;
    }
    printf("%d", ans);
    return 0;
}