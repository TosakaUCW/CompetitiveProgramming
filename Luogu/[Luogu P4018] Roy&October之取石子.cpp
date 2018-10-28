#include <stdio.h>

int T, x;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &x);
        puts(x % 6 ? "October wins!" : "Roy wins!");
    }
    return 0;
}