#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int P = 1e9 + 7;

int n, m;
long long ans1, ans2 = 1;
int head[N], num_edge;
int a[N];

int num_scc, timer;
int dfn[N], low[N], belong[N];
long long cnt[N], min[N];
bool inStack[N];
std::stack<int> S;

struct Node
{
    int next, to;
} edge[M];

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
    dfn[u] = low[u] = ++timer;
    S.push(u), inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++num_scc;
        int x;
        do
        {
            x = S.top(), S.pop(), inStack[x] = false;
            belong[x] = num_scc;
            if (a[x] < min[num_scc])
                min[num_scc] = a[x], cnt[num_scc] = 0;
            if (a[x] == min[num_scc])
                cnt[num_scc]++;
        } while (x != u);
    }
}

int main()
{
    memset(min, 0x7f, sizeof min);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = read();
    for (int i = 1; i <= m; i++)
        add_edge(read(), read());
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= num_scc; i++)
        ans1 += min[i], ans2 = (ans2 * cnt[i]) % P;
    printf("%lld %lld", ans1, ans2);
    return 0;
}