#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, m, ans, a[N], sum[N];

bool judge(int x)
{
    int tot = 0, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tot + a[i] <= x)
            tot += a[i];
        else
            cnt++, tot = a[i];
    }
    return cnt <= m;
}

int main()
{
    scanf("%d%d", &n, &m);
    int L = 0, R = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), L = std::max(L, a[i]), R += a[i];
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d", ans);
    return 0;
}