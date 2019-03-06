#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, m, cnt, ans;
int x, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), x = std::max(x, a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x)
            cnt++;
        else
            cnt = 0;
        ans = std::max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}