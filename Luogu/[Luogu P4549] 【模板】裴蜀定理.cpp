#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n, ans;

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        int a;
        scanf("%d", &a);
        if (a < 0)
            a = -a;
        ans = std::__gcd(ans, a);
    }
    printf("%d", ans);
    return 0;
}