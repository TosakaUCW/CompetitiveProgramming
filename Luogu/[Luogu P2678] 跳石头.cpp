#include <stdio.h>

const int N = 5e6 + 5;

int n, m, l, ans;
int a[N];

bool judge(int x)
{
    int cnt = m, dlt = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        dlt += a[i] - a[i - 1];
        if (dlt < x)
            cnt--;
        else
            dlt = 0;
        if (cnt < 0)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &l, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[n + 1] = l;
    int L = 1, R = l;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%d", ans);
    return 0;
}