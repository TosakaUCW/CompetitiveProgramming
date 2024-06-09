#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>
#include <stack>

typedef long long ll;

const ll N = 5e5 + 5;

ll n, ans;
char str[N];
std::stack<ll> S;
ll head[N], num_edge;
ll fa[N];
ll last[N], sum[N];

struct Node
{
    ll next, to;
} edge[N];

void add_edge(ll u, ll v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}

void dfs(int u)
{
    ll pos = 0;
    if (str[u] == ')')
    {
        if (!S.empty())
        {
            pos = S.top();
            S.pop();
            last[u] = last[fa[pos]] + 1;
        }
    }
    else
        S.push(u);
    sum[u] = sum[fa[u]] + last[u];
    for (int i = head[u]; i; i = edge[i].next)
        dfs(edge[i].to);
    if (pos != 0)
        S.push(pos);
    else if (!S.empty())
        S.pop();
}

signed main()
{
    scanf("%lld", &n);
    scanf("%s", str + 1);
    for (ll i = 2; i <= n; i++)
        std::cin >> fa[i], add_edge(fa[i], i);
    dfs(1);
    for (ll i = 1; i <= n; i++)
        ans ^= sum[i] * i;
    printf("%lld", ans);
    return 0;
}