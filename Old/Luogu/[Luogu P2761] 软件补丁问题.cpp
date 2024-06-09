#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

const int N = (1LL << 20) + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m, t[N];
char str[2][N];
int b[3][N], f[3][N];

struct node
{
    int cur, dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};

int dis[N];
bool vis[N];
std::priority_queue<node> Q;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof dis);
    Q.push(node{s, 0}), dis[s] = 0;
    for (int u, v; !Q.empty();)
    {
        u = Q.top().cur, Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 1; i <= m; i++)
            if ((u & b[1][i]) == b[1][i] and !(u & b[2][i]))
                if (dis[v = ((u | f[1][i]) ^ f[1][i]) | f[2][i]] > dis[u] + t[i])
                    dis[v] = dis[u] + t[i], Q.push(node{v, dis[v]});
    }
    printf("%lld", dis[0] == INF ? 0 : dis[0]);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%s%s", &t[i], str[0], str[1]);
        for (int j = 0; j < n; j++)
        {
            if (str[0][j] == '+')
                b[1][i] |= 1LL << j;
            else if (str[0][j] == '-')
                b[2][i] |= 1LL << j;
            if (str[1][j] == '-')
                f[1][i] |= 1LL << j;
            else if (str[1][j] == '+')
                f[2][i] |= 1LL << j;
        }
    }
    return dijkstra((1LL << n) - 1), 0;
}