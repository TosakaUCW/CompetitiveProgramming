#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

const int N = 8 + 5;
const int K = 6e4 + 5;

int k;
int d[N], dis[N][K];
int head[N], num_edge;

struct Node
{
    int next, to, dis;
} edge[N];
struct node
{
    int cur, r, dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};

void add_edge(int u, int v, int dis)
{
    edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge;
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dijkstra()
{
    int w = 2 * std::min(d[1], d[2]);
    memset(dis, 0x3f, sizeof dis);
    std::priority_queue<node> Q;
    Q.push(node{2, 0, 0});
    dis[2][0] = 0;
    while (!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        int u = now.cur, r = now.r;
        if (now.dis > dis[u][r] or now.dis >= k + w)
            continue;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to, nr = (r + edge[i].dis) % w;
            if (dis[v][nr] > dis[u][r] + edge[i].dis)
            {
                dis[v][nr] = dis[u][r] + edge[i].dis;
                Q.push(node{v, nr, dis[v][nr]});
            }
        }
    }
    int kmod = k % w, diff = w;
    for (int i = 0; i < w; ++i)
        if (dis[2][i] <= k)
        {
            if (i >= kmod)
                diff = std::min(diff, i - kmod);
            else
                diff = std::min(diff, w - (kmod - i));
        }
        else
            diff = std::min(diff, dis[2][i] - k);
    printf("%lld\n", k + diff);
}

signed main()
{
    for (int T = read(); T--; dijkstra())
    {
        k = read(), num_edge = 0;
        memset(edge, 0, sizeof edge);
        memset(head, 0, sizeof head);
        for (int i = 1; i <= 4; i++)
            d[i] = read();
        for (int i = 1; i <= 4; i++)
            add_edge(i, i % 4 + 1, d[i]), add_edge(i % 4 + 1, i, d[i]);
    }
    return 0;
}