#include <stdio.h>
#include <queue>
#include <stdlib.h>

const int N = 3e3 + 5;
const int M = 4e4 + 5;

int n, m, k;
int head[N], num_edge;
int dis[N][N], pre[N][N];
int ans[M];
std::vector<std::pair<int, int>> f[N];

struct Node
{
    int next, to;
} edge[M];
struct node
{
    int u, v;
};

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

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

bool judge(int x, int y, int z)
{
    for (int i = 0, n = f[x].size(); i < n; i++)
        if (f[x][i].first == y and f[x][i].second == z)
            return false;
    return true;
}

void print(int last)
{
    printf("%d\n1 ", dis[last][n]);
    int cnt = 0;
    for (int u = n, tmp; u != 1; tmp = last, last = pre[last][u], u = tmp)
        ans[++cnt] = u;
    for (int i = cnt; i; i--)
        printf("%d ", ans[i]);
}

void bfs()
{
    std::queue<node> Q;
    Q.push(node{0, 1});
    while (!Q.empty())
    {
        int last = Q.front().u, u = Q.front().v;
        Q.pop();
        if (u == n)
            print(last), exit(0);
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (judge(last, u, v) and !dis[u][v])
                pre[u][v] = last,
                dis[u][v] = dis[last][u] + 1,
                Q.push(node{u, v});
        }
    }
}

int main()
{
    n = read(), m = read(), k = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (int i = 1, x, y, z; i <= k; i++)
        x = read(), y = read(), z = read(), f[x].push_back(std::make_pair(y, z));
    bfs();
    puts("-1");
    return 0;
}