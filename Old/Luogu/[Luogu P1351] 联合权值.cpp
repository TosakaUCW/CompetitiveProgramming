#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;
const int P = 1e4 + 7;

int n;
int val[N], head[N], num_edge;
int ans_sum, ans_max;

struct Node
{
    int next, to;
} edge[N << 1];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
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
    n = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int u = 1; u <= n; u++)
    {
        int sum = 0, sum_sqr = 0;
        int max = 0, maxx = 0;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            sum = (sum + val[v]) % P;
            sum_sqr = (sum_sqr + (val[v] * val[v] % P)) % P;
            if (val[v] > max)
                maxx = max, max = val[v];
            else if (val[v] > maxx)
                maxx = val[v];
        }
        ans_sum = (ans_sum + (sum * sum % P) - sum_sqr % P) % P;
        ans_max = std::max(ans_max, max * maxx);
    }
    printf("%d %d", ans_max, (ans_sum + P) % P);
    return 0;
}