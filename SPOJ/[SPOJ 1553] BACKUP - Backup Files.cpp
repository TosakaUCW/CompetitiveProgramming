#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

typedef long long ll;

const ll N = 5e5 + 5;
const ll INF = 1 << 30;

ll n, m, ans;
ll L[N], R[N];
bool vis[N];
struct Node
{
    ll val, idx;
    bool friend operator<(Node a, Node b) { return a.val > b.val; }
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof vis);
        memset(L, 0, sizeof L);
        memset(R, 0, sizeof R);
        while (!Q.empty())
            Q.pop();
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", &a[i].val), a[i].idx = i;
        n--;
        for (int i = 1; i <= n; i++)
            L[i] = i - 1, R[i] = i + 1, a[i].val = a[i + 1].val - a[i].val, Q.push(a[i]);
        a[0].val = a[n + 1].val = INF;
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
        printf("%lld\n", ans);
    }
    return 0;
}