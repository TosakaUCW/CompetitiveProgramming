#include <stdio.h>
#include <algorithm>
#include <queue>

typedef long long ll;

const ll N = 5e5 + 5;

ll n, m, ans, max;
ll L[N], R[N];
bool vis[N];
struct Node
{
    ll val, idx;
    bool friend operator<(Node a, Node b) { return a.val < b.val; }
} a[N];

std::priority_queue<Node> Q;

ll get()
{
    while (1)
    {
        Node top = Q.top();
        Q.pop();
        if (!vis[top.idx])
            return top.idx;
    }
}

void del(ll x) { R[L[x]] = R[x], L[R[x]] = L[x], vis[x] = true; }

int main()
{
    scanf("%lld%lld", &n, &m);
    if (2 * m > n)
    {
        puts("Error!");
        return 0;
    }
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i].val), a[i].idx = i, Q.push(a[i]);
    for (ll i = 1; i <= n; i++)
        L[i] = i - 1, R[i] = i + 1;
    // L[1] = n, R[n] = 1;
    while (m--)
    {
        ll x = get();
        if (a[x].val <= 0)
            break;
        ans += a[x].val;
        // printf("%d\n", a[x].val);
        a[x].val = a[L[x]].val + a[R[x]].val - a[x].val;
        Q.push({a[x]});
        del(L[x]), del(R[x]);
    }
    printf("%lld", ans);
    return 0;
}