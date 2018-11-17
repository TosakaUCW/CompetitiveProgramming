#include <math.h>
#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 3e4;
struct UnionFindSet
{
    int fa[N + 5], dis[N + 5], size[N + 5];
    void init()
    {
        Rep(i, 1, N)
        {
            fa[i] = i;
            dis[i] = 0;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (fa[x] == x)
            return fa[x];
        int k = fa[x];
        fa[x] = find(fa[x]);
        //update dis
        dis[x] += dis[k];
        //update size
        size[x] = size[fa[x]];
        return fa[x];
    }
    void merge(int x, int y)
    {
        int dx = find(x);
        int dy = find(y);
        fa[dx] = dy;
        //update dis
        dis[dx] += size[dy];
        //update size
        size[dx] += size[dy];
        size[dy] = size[dx];
    }
    void query(int x, int y)
    {
        int dx = find(x);
        int dy = find(y);
        if (dx != dy)
            printf("-1\n");
        else
            printf("%d\n", abs(dis[x] - dis[y]) - 1);
    }
} ufs;

int main()
{
    ufs.init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char c;
        int a, b;
        scanf("\n%c%d%d", &c, &a, &b);
        if (c == 'M')
            ufs.merge(a, b);
        if (c == 'C')
            ufs.query(a, b);
    }
    return 0;
}