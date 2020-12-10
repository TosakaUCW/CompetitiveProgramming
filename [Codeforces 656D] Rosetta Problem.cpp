#include <stdio.h>

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    while (n)
    {
        ans += (n % 8 == 1);
        n /= 8;
    }
    printf("%d", ans);
    return 0;
}