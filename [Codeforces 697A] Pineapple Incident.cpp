#include <stdio.h>

int t, s, x;

int main()
{
    scanf("%d%d%d", &t, &s, &x);
    int k = x - t;
    if (k < s and k != 0)
        printf("NO");
    else if (k % s == 0 or k % s == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}