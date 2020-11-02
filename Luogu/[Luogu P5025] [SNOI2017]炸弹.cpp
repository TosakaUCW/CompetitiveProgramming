#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stack>

#define int long long

const int N = 1e7 + 5;
const int M = N << 1;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, node_max;
int head[N], num_edge;
int idx[N], lef[N], rig[N];
std::vector<int> G[N];
bool vis[N];

struct Node
{
    int next, to;
} edge[M];
struct Boobs
{
    int x, r;
} B[N];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    struct Tree_Node
    {
        int l, r;
    } t[N];
    void build(int p, int l, int r)
    {
        t[p] = {l, r}, node_max = std::max(node_max, p);
        if (l == r)
        {
            idx[l] = p;
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r);
        add_edge(p, ls), add_edge(p, rs);
    }
    void update(int p, int l, int r, int x, int y, int k)
    {
        if (x <= l and r <= y)
        {
            if (k != p)
                add_edge(k, p);
            return;
        }
        if (x <= mid)
            update(ls, l, mid, x, y, k);
        if (mid < y)
            update(rs, mid + 1, r, x, y, k);
    }
} T;

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

struct tarjan
{
    int dfn[N], low[N], belong[N];
    int num_scc, timer;
    std::stack<int> S;
    bool inStack[N];
    void main(int u)
    {
        dfn[u] = low[u] = ++timer;
        S.push(u), inStack[u] = true;
        for (int i = head[u], v; i; i = edge[i].next)
        {
            if (!dfn[v = edge[i].to])
                main(v), low[u] = std::min(low[u], low[v]);
            else if (inStack[v])
                low[u] = std::min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u])
        {
            int x;
            num_scc++;
            do
            {
                x = S.top(), S.pop(), belong[x] = num_scc;
                inStack[x] = false;
                lef[num_scc] = std::min(lef[num_scc], T.t[x].l);
                rig[num_scc] = std::max(rig[num_scc], T.t[x].r);
            } while (x != u);
        }
    }
    void rebuild()
    {
        for (int u = 1; u <= node_max; u++)
            for (int i = head[u], v; i; i = edge[i].next)
                if (belong[v = edge[i].to] != belong[u])
                    G[belong[u]].push_back(belong[v]);
        for (int i = 1; i <= num_scc; i++)
        {
            std::sort(G[i].begin(), G[i].end());
            G[i].erase(std::unique(G[i].begin(), G[i].end()), G[i].end());
        }
    }
} tarjan;

void dfs(int u)
{
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v])
        {
            lef[u] = std::min(lef[u], lef[v]);
            rig[u] = std::max(rig[u], rig[v]);
            continue;
        }
        dfs(v);
        lef[u] = std::min(lef[u], lef[v]);
        rig[u] = std::max(rig[u], rig[v]);
    }
}

signed main()
{
    memset(lef, 0x3f, sizeof lef);
    n = read();
    std::vector<int> Q;
    for (int i = 1; i <= n; i++)
        B[i].x = read(), B[i].r = read(), Q.push_back(B[i].x);
    Q.push_back(INF), T.build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (!B[i].r)
            continue;
        int lt = B[i].x - B[i].r, rt = B[i].x + B[i].r;
        lt = std::lower_bound(Q.begin(), Q.end(), lt) - Q.begin() + 1;
        rt = std::upper_bound(Q.begin(), Q.end(), rt) - Q.begin();
        T.update(1, 1, n, lt, rt, idx[i]);
        T.t[idx[i]] = {lt, rt};
    }
    tarjan.main(1);
    tarjan.rebuild();
    for (int i = 1; i <= tarjan.num_scc; i++)
        if (!vis[i])
            dfs(i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = tarjan.belong[idx[i]];
        (ans += (rig[k] - lef[k] + 1) * i % P) %= P;
    }
    printf("%lld", ans);
    return 0;
}