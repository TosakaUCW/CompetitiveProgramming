#include <stdio.h>
#include <algorithm>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", x / 2);
    }
    return 0;
}