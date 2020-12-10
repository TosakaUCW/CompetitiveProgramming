#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stdlib.h>

const int N = 1e5 + 5;

int n, m, ans;
int head[N], num_edge;
int dis[N], inQcnt[N];
bool inQ[N];
std::queue<int> Q;

struct Node
{
    int next, to, dis;
} edge[N];

void add_edge(int u, int v, int dis)
{
    edge[++num_edge] = Node{head[u], v, dis};
    head[u] = num_edge;
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

bool SPFA(int st)
{
    memset(dis, 0x3f, sizeof dis);
    Q.push(st);
    dis[st] = 0;
    inQ[st] = true, inQcnt[st] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(), inQ[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!inQ[v])
                {
                    inQ[v] = true, inQcnt[v]++;
                    Q.push(v);
                    if (inQcnt[v] > n)
                    {
                        puts("Forever love");
                        exit(0);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, -dis);
    SPFA(1);
    ans = dis[n];
    SPFA(n);
    printf("%d", std::min(ans, dis[1]));
    return 0;
}