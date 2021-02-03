#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>

typedef unsigned long long ull;

#define getRand() ((ull(rand()) << 30) + rand())

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = N << 2;

int n;
int head[N], num_edge;
ull sum[N], ans;
bool vis[N];
std::unordered_map<int, ull> map;

struct Node
{
    int next, to;
    ull dis;
} edge[M];

void add_edge(int u, int v, ull dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

int cnt, prime[N];
bool isPrime[N];

void Euler(int n)
{
    memset(isPrime, true, sizeof isPrime);
    isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt and i * prime[j] <= n; j++)
        {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void dfs(int u)
{
    vis[u] = true;
    for (int i = head[u], v; v = edge[i].to; i = edge[i].next)
        if (!vis[v])
            sum[v] = sum[u] ^ edge[i].dis, dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    srand(time(0)), Euler(1e4), n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        ull dis = 0;
        for (int j = 1; j <= cnt and prime[j] * prime[j] <= w; j++)
        {
            bool tot = 0;
            while (w % prime[j] == 0)
                w /= prime[j], tot ^= 1;
            if (tot)
            {
                while (!map[prime[j]])
                    map[prime[j]] = getRand();
                dis ^= map[prime[j]];
            }
        }
        if (w > 1)
        {
            while (!map[w])
                map[w] = getRand();
            dis ^= map[w];
        }
        add_edge(u, v, dis), add_edge(v, u, dis);
    }
    sum[1] = 0, dfs(1), std::sort(sum + 1, sum + 1 + n);
    int last = 0;
    for (int i = 1; i <= n; i++)
        if (i == n or sum[i] != sum[i + 1])
        {
            ans += ull(i - last) * (i - last - 1);
            last = i;
        }
    return printf("%llu", ans), 0;
}