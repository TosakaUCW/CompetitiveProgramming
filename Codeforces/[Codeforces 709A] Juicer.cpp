#include <stdio.h>

int n, b, d, x, sum, ans;

int main()
{
    scanf("%d%d%d", &n, &b, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x > b)
            continue;
        if (sum + x > d)
        {
            ans++;
            sum = 0;
        }
        else
            sum += x;
    }
    printf("%d", ans);
    return 0;
}