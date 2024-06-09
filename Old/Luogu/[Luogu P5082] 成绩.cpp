#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n, a, b;
double ans;

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        int tmp;
        scanf("%d", &tmp);
        a += tmp;
    }
    Rep(i, 1, n)
    {
        int tmp;
        scanf("%d", &tmp);
        b += tmp;
    }
    ans = (3.0 * a - 2.0 * b) / (1.0 * (a - b));
    printf("%.6f",ans);
    return 0;
}