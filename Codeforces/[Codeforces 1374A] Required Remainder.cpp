#include <stdio.h>

int x, y, n;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &x, &y, &n);
        printf("%d\n", (n - y) / x * x + y);
    }
    return 0;
}