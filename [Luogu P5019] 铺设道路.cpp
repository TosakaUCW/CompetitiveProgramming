#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N=1e5;

int n, a[N+5];
long long ans;

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
        scanf("%d", &a[i]);
    Rep(i,1,n)
        ans+=std::max(a[i]-a[i-1],0);
    printf("%lld", ans);
    return 0;
}