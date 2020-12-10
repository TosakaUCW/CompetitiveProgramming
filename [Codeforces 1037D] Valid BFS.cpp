#include <stdio.h>
#include <queue>
#include <set>
#include <vector>

const int N = 2e5 + 5;

int n;
int head[N], num_edge;
bool vis[N];
std::queue<int> Q, opt;
std::set<int> set;

struct Node
{
    int next, to;
} edge[2 * N];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void BFS(int s)
{
    if (opt.front() != 1)
    {
        puts("No");
        return;
    }
    Q.push(s);
    opt.pop();
    vis[s] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (!vis[v])
                set.insert(v);
        }
        while (!set.empty())
            if (set.count(opt.front()))
            {
                set.erase(opt.front());
                Q.push(opt.front());
                opt.pop();
            }
            else
            {
                puts("No");
                return;
            }
    }
    puts("Yes");
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        opt.push(x);
    }
    BFS(1);
    return 0;
}