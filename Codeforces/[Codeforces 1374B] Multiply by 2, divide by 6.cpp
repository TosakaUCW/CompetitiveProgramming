#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x, a = 0, b = 0;
        scanf("%d", &x);
        while (x % 2 == 0)
            x /= 2, a++;
        while (x % 3 == 0)
            x /= 3, b++;
        if (x != 1 or a > b)
            puts("-1");
        else
            printf("%d\n", a + (b - a) * 2);
    }
    return 0;
}