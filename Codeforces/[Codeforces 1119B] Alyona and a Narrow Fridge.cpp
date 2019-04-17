#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;

int n, m, ans;
int a[N], b[N];

bool cmp(int a, int b) { return a > b; }

bool judge(int x)
{
    long long res = 0;
    for (int i = 1; i <= x; i++)
        b[i] = a[i];
    std::sort(b + 1, b + 1 + x, cmp);
    for (int i = 1; i <= x; i += 2)
        res += b[i];
    //printf("%d %d\n", x, res);
    return res <= m;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (judge(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d", ans);
    return 0;
}