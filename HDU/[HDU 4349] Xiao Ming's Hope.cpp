#include <stdio.h>

int n;

int main()
{
    while (~scanf("%d", &n))
    {
        int k = 0, ans = 1;
        while (n)
            k += n % 2, n /= 2;
        for (int i = 1; i <= k; i++)
            ans *= 2;
        printf("%d\n", ans);
    }
    return 0;
}