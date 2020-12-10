#include <stdio.h>
#include <algorithm>

int f[5];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 3; i++)
            scanf("%d", &f[i]);
        std::sort(f + 1, f + 1 + 3);
        if (f[2] != f[3])
            puts("NO");
        else
            printf("YES\n%d %d %d\n", f[1], f[1], f[2]);
    }
    return 0;
}