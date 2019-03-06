#include <stdio.h>

int n, v, ans;

int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1, cur = 0; i <= n; cur--, i++)
    {
        if (n - i <= cur)
            break;
        if (cur < v and i + cur < n and i + v >= n)
        {
            ans += (n - i - cur) * i, cur = v;
            break;
        }
        if (cur < v and i + cur < n)
            ans += (v - cur) * i, cur = v;
    }
    printf("%d", ans);
    return 0;
}