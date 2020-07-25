#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n, k, L = 1, R, ans;
int a[N];

bool judge(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (cnt % 2 == 1 and a[i] <= x or cnt % 2 == 0)
            cnt++;
    if (cnt >= k)
        return true;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (cnt % 2 == 0 and a[i] <= x or cnt % 2 == 1)
            cnt++;
    return cnt >= k;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), R = std::max(R, a[i]);
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