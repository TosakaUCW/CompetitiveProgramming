#include <stdio.h>
#include <algorithm>

const int N = 4e4 + 5;
const int M = 4e5 + 5;

int n, m, ans;
int fa[N << 1];

struct Node
{
    int u, v, dis;
    // bool friend operator<(Node a, Node b) { a.dis > b.dis; }
} edge[M];

bool cmp(Node a, Node b) { return a.dis > b.dis; }

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].dis);
    std::sort(edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= n * 2; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int fx = find(edge[i].u);
        int fy = find(edge[i].v);
        if (fx != fy)
            fa[fx] = find(edge[i].v + n), fa[fy] = find(edge[i].u + n);
        else
        {
            printf("%d", edge[i].dis);
            return 0;
        }
    }
    puts("0");
    return 0;
}