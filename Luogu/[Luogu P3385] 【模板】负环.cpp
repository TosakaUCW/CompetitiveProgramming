#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e3 + 5;
const int M = 6e3 + 5;

int T, n, m, num_edge;
int cnt[N], dis[N], head[N];
bool inQueue[N];
std::queue<int> Q;

struct Node
{
    int next, to, dis;
} edge[M];

inline void read(int &x)
{
    int c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar())
        if (c == '-')
            f = true;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    if (f)
        x = -x;
}

inline void add_edge(int u, int v, int dist)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dist;
    head[u] = num_edge;
}

inline void SPFA(int s)
{
    memset(cnt, 0, sizeof cnt);
    memset(dis, 0x3f, sizeof dis);
    memset(inQueue, false, sizeof inQueue);
    while (!Q.empty())
        Q.pop();
    Q.push(s);
    inQueue[s] = true, dis[s] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQueue[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            int dist = edge[i].dis;
            if (dis[v] > dis[u] + dist)
            {
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                {
                    puts("YE5");
                    return;
                }
                dis[v] = dis[u] + dist;
                if (!inQueue[v])
                {
                    Q.push(v);
                    inQueue[v] = true;
                }
            }
            else if (dis[v] == dis[u] + dist and dist > 0)
            {
                cnt[v] += cnt[u];
                if (cnt[v] >= n)
                {
                    puts("YE5");
                    return;
                }
            }
        }
    }
    puts("N0");
}

int main()
{
    read(T);
    while (T--)
    {
        num_edge = 0;
        memset(head, 0, sizeof head);
        read(n), read(m);
        Rep(i, 1, m)
        {
            int u, v, dist;
            read(u), read(v), read(dist);
            add_edge(u, v, dist);
            if (dist >= 0)
                add_edge(v, u, dist);
        }
        SPFA(1);
    }
    return 0;
}