#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 2e5 + 5;

ll n, cnt, maxn;
ll raw[N], c[N];
ll ans;

struct Node
{
    ll x, y1, y2, opt;
} line[N];

bool cmp(Node A, Node B) { return A.x == B.x ? A.opt > B.opt : A.x < B.x; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P1884_10.in", "r", stdin);
    freopen("P1884_10.ans", "w", stdout);
#endif // !ONLINE_JUDGE
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        std::swap(y1, y2);
        line[i * 2 - 1] = Node{x1, y1, y2, 1};
        line[i * 2] = Node{x2, y1, y2, -1};
        raw[++cnt] = y1, raw[++cnt] = y2;
    }
    std::sort(raw + 1, raw + 1 + cnt);
    cnt = std::unique(raw + 1, raw + 1 + cnt) - raw - 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        int pos1 = std::lower_bound(raw + 1, raw + cnt + 1, line[i].y1) - raw;
        int pos2 = std::lower_bound(raw + 1, raw + cnt + 1, line[i].y2) - raw;
        line[i].y1 = pos1;
        line[i].y2 = pos2;
    }
    std::sort(line + 1, line + 1 + 2 * n, cmp);
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = line[i].y1; j < line[i].y2; j++)
            c[j] += line[i].opt;
        for (int j = 1; j < cnt; j++)
            if (c[j] > 0)
                ans += (line[i + 1].x - line[i].x) * (raw[j + 1] - raw[j]);
    }
    printf("%lld", ans);
    return 0;
}