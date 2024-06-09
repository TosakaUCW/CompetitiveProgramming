#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, m, ans, a[N];

bool judge(int x)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += a[i] / x;
        if (cnt > m)
            return false;
    }
    return cnt <= m;
}

int main()
{
    int L = 0, R = 0;
    scanf("%d%d%d", &R, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
        a[i] = a[i + 1] - a[i] - 1;
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