#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e3 + 5;
const int M = N * N;

int n;
int a[N], f[N], col[N];
int head[N], num_edge;

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void bfs(int s)
{
    std::queue<int> Q;
    Q.push(s), col[s] = 1;
    for (int u; !Q.empty();)
    {
        u = Q.front(), Q.pop();
        for (int i = head[u], v; i; i = edge[i].next)
            if (!col[v = edge[i].to])
                col[v] = -col[u], Q.push(v);
            else if (col[v] != -col[u])
                puts("0"), exit(0);
    }
}

void emulate(int cnt = 1)
{
    std::stack<int> S[2];
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
            S[0].push(a[i]), printf("a ");
        else
            S[1].push(a[i]), printf("c ");
#define check(x) (!x.empty() and x.top() == cnt)
        for (; check(S[0]) or check(S[1]); cnt++)
            if (check(S[0]))
                S[0].pop(), printf("b ");
            else
                S[1].pop(), printf("d ");
    }
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    f[n + 1] = 2147483647;
    for (int i = n; i; i--)
        f[i] = std::min(f[i + 1], a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > f[j + 1] and a[i] < a[j])
                add_edge(i, j), add_edge(j, i);
    for (int i = 1; i <= n; i++)
        if (!col[i])
            bfs(i);
    emulate();
    return 0;
}