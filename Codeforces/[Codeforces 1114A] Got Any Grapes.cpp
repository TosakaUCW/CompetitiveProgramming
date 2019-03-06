#include <stdio.h>

int a, b, c;
int x, y, z;

int main()
{
    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d", &a, &b, &c);
    if ((a < x) or (a + b < x + y) or (a + b + c < x + y + z))
        puts("NO");
    else
        puts("YES");
    return 0;
}