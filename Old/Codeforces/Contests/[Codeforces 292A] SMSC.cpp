#include <stdio.h>
#include <algorithm>

int max, n, t, x;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        x = std::max(0, x - a + t);
        x += b;
        max = std::max(max, x);
        t = a;
    }
    printf("%d %d", t + x, max);
    return 0;
}