#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;

int n, m, ans;
int a[N + 5];

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
        scanf("%d", &a[i]);
    Rep(i, 1, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ans += std::min(a[x], a[y]);
    }
    printf("%d", ans);
    return 0;
}