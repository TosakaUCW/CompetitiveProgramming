#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e4 + 5;

int n, k;
int a[N], l[N], r[N];
int ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + n);
    l[1] = 1, r[n] = 1;
    for (int i = 2, p = 1; i <= n; i++)
    {
        while (a[p] + k < a[i])
            p++;
        l[i] = std::max(l[i - 1], i - p + 1);
    }
    for (int i = n - 1, p = n; i; i--)
    {
        while (a[i] + k < a[p])
            p--;
        r[i] = std::max(r[i + 1], p - i + 1);
    }
    for (int i = 1; i < n; i++)
        ans = std::max(ans, l[i] + r[i + 1]);
    printf("%d", ans);
    return 0;
}