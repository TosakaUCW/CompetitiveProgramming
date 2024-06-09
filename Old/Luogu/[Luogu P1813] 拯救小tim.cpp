#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e2 + 5;
const int M = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int n, m, s, t, ans = INF, L = INF, R = 0;
int head[N], num_edge;
int dis[N];

struct Node
{
    int next, to, dis, min, max;
} edge[M];
struct node
{
    int cur, dis;
    bool friend operator<(node a, node b) { return a.dis < b.dis; }
};

std::priority_queue<node> Q;

void add_edge(int u, int v, int min, int max, int dis) { edge[++num_edge] = Node{head[u], v, dis, min, max}, head[u] = num_edge; }

int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' or ch > '9')
        ch = getchar();
    while (ch >= '0' and ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int main()
{
    n = read(), m = read(), s = read(), t = read();
    for (int i = 1, u, v, dis, min, max; i <= m; i++)
    {
        u = read(), v = read(), min = read(), max = read(), dis = read();
        if (max - min < dis)
            continue;
        add_edge(u, v, min, max, dis);
        if (u == s)
            L = std::min(L, min), R = std::max(R, min);
    }
    for (int origin = L; origin <= R; origin++)
    {
        memset(dis, 0x3f, sizeof dis);
        dis[s] = origin, Q.push(node{s, 0});
        for (int u, tmp; !Q.empty();)
        {
            u = Q.top().cur, Q.pop();
            for (int i = head[u]; i; i = edge[i].next)
                if (dis[u] + edge[i].dis <= edge[i].max)
                {
                    tmp = std::max(edge[i].min, dis[u]) + edge[i].dis;
                    if (tmp < dis[edge[i].to])
                        dis[edge[i].to] = tmp, Q.push(node{edge[i].to, dis[edge[i].to]});
                }
        }
        if (dis[t] != INF)
            ans = std::min(ans, dis[t] - dis[s]);
        else
            break;
    }
    if (ans != INF)
        printf("%d", ans);
    else
        puts("Impossible");
    return 0;
}