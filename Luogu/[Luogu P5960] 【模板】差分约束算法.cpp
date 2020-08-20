#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e7 + 5;
const int INF = 2147483647 / 3;

int n, m;
int head[N], num_edge;
bool inQ[N];
int dis[N], inQcnt[N];
std::queue<int> Q;

struct Node
{
    int next, to, dis;
} edge[N << 1];

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

bool SPFA(int st)
{
    for (int i = 0; i <= n; i++)
        dis[i] = INF;
    dis[st] = 0;
    Q.push(st);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQ[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!inQ[v])
                    Q.push(v), inQ[v] = true, inQcnt[v]++;
                if (inQcnt[v] > n)
                    return false;
            }
        }
    }
    return true;
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

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(v, u, dis);
    for (int i = 1; i <= n; i++)
        add_edge(0, i, 0);
    if (!SPFA(0))
        puts("NO");
    else
        for (int i = 1; i <= n; i++)
            printf("%d ", dis[i]);
    return 0;
}