// luogu-judger-enable-o2
#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e5 + 5;

int T, n;
int b[2 * N];

struct Node
{
    int x, y, e;
    friend bool operator<(Node a, Node b) { return a.e > b.e; }
} a[N];

struct Union_Find_Set
{
    int fa[N];
    void clear() { memset(fa, 0, sizeof fa); }
    void init(int n)
    {
        Rep(i, 1, n)
            fa[i] = i;
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }
} UFS;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        UFS.clear();
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        scanf("%d", &n);
        Rep(i, 1, n)
        {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].e);
            b[2 * i - 1] = a[i].x;
            b[2 * i] = a[i].y;
        }
        std::sort(b + 1, b + 1 + 2 * n);
        int tot = std::unique(b + 1, b + 1 + 2 * n) - b;
        UFS.init(tot);
        Rep(i, 1, n)
        {
            a[i].x = std::lower_bound(b + 1, b + 1 + tot, a[i].x) - b;
            a[i].y = std::lower_bound(b + 1, b + 1 + tot, a[i].y) - b;
        }
        std::sort(a + 1, a + 1 + n);
        bool flag = true;
        Rep(i, 1, n)
        {
            if (a[i].e == 1)
                UFS.unite(a[i].x, a[i].y);
            else
            {
                int fx = UFS.find(a[i].x), fy = UFS.find(a[i].y);
                if (fx == fy)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
}