#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e5;
const int INF = 1 << 30;

int n, ans = INF;
int fa[N + 5];

int find(int x, int &depth)
{
    depth++;
    return fa[x] != x ? find(fa[x], depth) : x;
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
        fa[i] = i;
    Rep(i, 1, n)
    {
        int t, depth = 0;
        scanf("%d", &t);
        if (find(t, depth) == i)
            ans = std::min(ans, depth);
        else
            fa[i] = t;
    }
    printf("%d", ans);
    return 0;
}