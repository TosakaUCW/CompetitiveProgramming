#include <queue>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e3 + 5;
const int M = 6e3 + 5;

int n, m;
int head[N], num_edge;
int dis[N], inQcnt[N];
bool inQ[N];

struct Node
{
    int next, to, dis;
} edge[M];

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

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

bool SPFA()
{
    memset(inQ, false, sizeof inQ);
    memset(inQcnt, 0, sizeof inQcnt);
    memset(dis, 0x3f, sizeof dis);
    std::queue<int> Q;
    while (!Q.empty())
        Q.pop();
    Q.push(1);
    inQ[1] = true, dis[1] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        inQ[u] = false;
        Q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!inQ[v])
                {
                    inQ[v] = true;
                    Q.push(v);
                    inQcnt[v]++;
                    if (inQcnt[v] >= n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int T = read();
    while (T--)
    {
        num_edge = 0;
        memset(head, 0, sizeof head);
        n = read(), m = read();
        for (int i = 1, u, v, dis; i <= m; i++)
        {
            u = read(), v = read(), dis = read();
            add_edge(u, v, dis);
            if (dis >= 0)
                add_edge(v, u, dis);
        }
        if (SPFA())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}