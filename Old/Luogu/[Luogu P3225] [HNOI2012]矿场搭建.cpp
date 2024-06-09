#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <vector>

const int N = 1e5 + 5;

int n, m;
int head[N], num_edge;

int timer, num_v_dcc;
int dfn[N], low[N], size[N];
bool cut[N];
std::stack<int> S;
std::vector<int> DCC[N];

struct Node
{
    int next, to;
} edge[N];

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

void tarjan(int u)
{
    int fa = 0;
    dfn[u] = low[u] = ++timer;
    S.push(u);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                fa++, num_v_dcc++;
                if (u != 1 or fa > 1)
                    cut[u] = true;
                DCC[num_v_dcc].push_back(u);
                int x = 0;
                do
                    x = S.top(), S.pop(), DCC[num_v_dcc].push_back(x);
                while (x != v);
            }
        }
        else
            low[u] = std::min(low[u], dfn[v]);
    }
}

int main()
{
    int cas = 1;
    for (m = read(); m; m = read(), cas++)
    {
        S = std::stack<int>();
        for (int i = 1; i <= num_v_dcc; i++)
            DCC[i].clear();
        n = timer = num_edge = num_v_dcc = 0;
        long long ans1 = 0, ans2 = 1;
        memset(head, 0, sizeof head);
        memset(edge, 0, sizeof edge);
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(cut, false, sizeof cut);

        for (int i = 1, u, v; i <= m; n = std::max(n, std::max(u, v)), i++)
            u = read(), v = read(), add_edge(u, v), add_edge(v, u);
        tarjan(1);
        for (int i = 1; i <= num_v_dcc; i++)
        {
            int x = DCC[i].size(), y = 0;
            for (int j = 0; j < x; j++)
                y += cut[DCC[i][j]];
            if (y == 1)
                ans1++, ans2 *= x - 1;
            if (y == 0)
                ans1 += 2, ans2 *= x * (x - 1) / 2;
        }

        printf("Case %d: %lld %lld\n", cas, ans1, ans2);
    }
    return 0;
}