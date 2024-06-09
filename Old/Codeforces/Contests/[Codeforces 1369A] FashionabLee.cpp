#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x;
        scanf("%d", &x);
        x % 4 ? puts("NO") : puts("YES");
    }
    return 0;
}