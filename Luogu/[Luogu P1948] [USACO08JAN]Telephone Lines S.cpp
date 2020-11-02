#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e3 + 5;
const int M = 2e4 + 5;

int n, m, k, dis[N];
int head[N], num_edge;
bool inQ[N];

struct Node
{
    int next, to, dis;
} edge[M];

std::queue<int> Q;

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

bool judge(int x)
{
    memset(dis, 0x3f, sizeof dis);
    Q.push(1), inQ[1] = true, dis[1] = 0;
    for (int u; !Q.empty();)
    {
        // puts("1");
        u = Q.front(), Q.pop(), inQ[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].dis > x;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!inQ[v])
                    Q.push(v), inQ[v] = true;
            }
        }
    }
    return dis[n] <= k;
}

int main()
{
    int L = 0, R = 0, res = -1;
    n = read(), m = read(), k = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis), R += dis;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (judge(mid))
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    return printf("%d", res), 0;
}