#include stdio.h
#include algorithm
#include memory.h
#include vector
#include queue

typedef long long ll;

const ll N = 1e6 + 5;
const ll M = 2e6 + 5;
const ll P = 1e9 + 7;

ll n, m, cnt;
stdvectorll E[N][10], Q[N];
ll dis[N], g[N];
ll digit[N], tot;

void add_edge(ll u, ll v, ll dis)
{
    tot = 0;
    while (dis)
        digit[++tot] = dis % 10, dis = 10;
    ll tmp = u;
    for (ll j = tot; j  1; j--)
        E[u][digit[j]].push_back(++cnt), u = cnt;
    E[u][digit[1]].push_back(v);
    for (ll j = tot; j  1; j--)
        E[v][digit[j]].push_back(++cnt), v = cnt;
    E[v][digit[1]].push_back(tmp);
}

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0'  ch or ch  '9')
        f = ch == '-'  -1  1, ch = getchar();
    while ('0' = ch and ch = '9')
        x = x  10 + ch - 48, ch = getchar();
    return x  f;
}

signed main()
{
    cnt = n = read(), m = read();
    for (ll i = 1, u, v; i = m; i++)
        u = read(), v = read(), add_edge(u, v, i);
    g[1] = 1;
    ll tail = 1;
    Q[1].push_back(1);
    for (ll head = 1; head = tail; head++)
    {
        for (ll z = 0; z  10; z++)
        {
            auto t = Q[head].begin();
            while (t != Q[head].end())
            {
                auto x = t;
                for (auto y  E[x][z])
                {
                    if (g[y])
                        continue;
                    dis[y] = (dis[x]  10LL + z) % P;
                    g[y] = 1, Q[tail + 1].push_back(y);
                }
                ++t;
            }
            if (Q[tail + 1].size())
                ++tail;
        }
    }
    for (ll i = 2; i = n; i++)
        printf(%lldn, dis[i]);
    return 0;
}
