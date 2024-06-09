#include <stdio.h>
#include <algorithm>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if (i % 2 == 1 and x < 0)
                x = -x;
            if (i % 2 == 0 and x > 0)
                x = -x;
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}