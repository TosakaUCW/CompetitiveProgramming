#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <set>

const int N = 5e4 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;

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

int dfs(int u, int fa, int &len, int limit)
{
    int ans = 0;
    std::multiset<int> S;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to, dis = edge[i].dis;
        if (v == fa)
            continue;
        int res = 0;
        ans += dfs(v, u, res, limit);
        res += dis;
        if (res >= limit)
            ans++;
        else
            S.insert(res);
    }
    len = 0;
    while (!S.empty())
    {
        int res = *S.begin();
        S.erase(S.begin());
        std::multiset<int>::iterator it = S.lower_bound(limit - res);
        if (it != S.end())
            S.erase(it), ans++;
        else
            len = std::max(len, res);
    }
    return ans;
}

int main()
{
    n = read(), m = read();
    int L = 0, R = 0, res = -1;
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis), R += dis;
    while (L <= R)
    {
        int mid = L + R >> 1, len = 0;
        if (dfs(1, 0, len, mid) >= m)
            res = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%d", res);
    return 0;
}