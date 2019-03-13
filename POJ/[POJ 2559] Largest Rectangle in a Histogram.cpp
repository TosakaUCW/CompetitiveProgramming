#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long ll;

const int N = 1e6 + 5;

ll n, ans, a[N];
ll l[N], r[N];
ll queue[3 * N];

int main()
{
    while (scanf("%lld", &n) and n != 0)
    {
        memset(queue, 0, sizeof queue);
        ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int tail = 0;
        for (int i = 1; i <= n; i++)
        {
            while (tail and a[i] <= a[queue[tail]])
                tail--;
            l[i] = i - queue[tail] - 1;
            queue[++tail] = i;
        }
        tail = 0;
        queue[0] = n + 1;
        for (int i = n; i >= 1; i--)
        {
            while (tail and a[i] <= a[queue[tail]])
                tail--;
            r[i] = queue[tail] - i - 1;
            queue[++tail] = i;
        }
        for (int i = 1; i <= n; i++)
            ans = std::max(ans, a[i] * (l[i] + r[i] + 1));
        printf("%lld\n", ans);
    }
    return 0;
}