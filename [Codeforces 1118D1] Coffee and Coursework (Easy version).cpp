#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n, m;
int a[N];

bool judge(int x)
{
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += std::max(0, a[i] - (i - 1) / x);
        if (tot >= m)
            return true;
    }
    return false;
}

void binary_search()
{
    int l = 1, r = n, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (judge(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    if (ans >= 1 and ans <= n)
        printf("%d", ans);
    else
        printf("-1");
}

bool cmp(int a, int b) { return a > b; }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + n, cmp);
    binary_search();
    return 0;
}