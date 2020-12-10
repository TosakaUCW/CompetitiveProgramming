#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m;
int head[N], num_edge;
int dis[N][2];
bool inQ[N];
std::queue<int> Q;

struct Node
{
    int next, to, dis;
} edge[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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

void SPFA(int s)
{
    memset(dis, 0x3f, sizeof dis);
    Q.push(s), inQ[s] = true;
    dis[s][0] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(), inQ[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            bool flag = false;
            if (dis[v][0] > dis[u][0] + edge[i].dis)
                dis[v][1] = dis[v][0], dis[v][0] = dis[u][0] + edge[i].dis, flag = true;
            if (dis[v][0] < dis[u][0] + edge[i].dis and dis[v][1] > dis[u][0] + edge[i].dis)
                dis[v][1] = dis[u][0] + edge[i].dis,
                flag = true;
            if (dis[v][1] > dis[u][1] + edge[i].dis)
                dis[v][1] = dis[u][1] + edge[i].dis,
                flag = true;
            if (flag and !inQ[v])
                Q.push(v), inQ[v] = true;
        }
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    SPFA(n);
    printf("%d", dis[1][1]);
    return 0;
}