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
struct node
{
    ll L, R, cnt, len;
} tree[N << 4];

bool cmp(Node A, Node B)
{
    return A.x == B.x ? A.opt > B.opt : A.x < B.x;
}

void build(int p, int L, int R)
{
    tree[p].L = L, tree[p].R = R;
    if (L == R)
        return;
    int mid = (tree[p].L + tree[p].R) / 2;
    build(p * 2, L, mid), build(p * 2 + 1, mid + 1, R);
}

void push(int p)
{
    if (tree[p].cnt >= 1)
        tree[p].len = raw[tree[p].R + 1] - raw[tree[p].L];
    else
        tree[p].len = tree[p * 2].len + tree[p * 2 + 1].len;
}

void add(int p, int L, int R, int val)
{
    if (L <= tree[p].L and tree[p].R <= R)
    {
        tree[p].cnt += val;
        push(p);
        return;
    }
    int mid = (tree[p].L + tree[p].R) / 2;
    if (L <= mid)
        add(p * 2, L, R, val);
    if (mid < R)
        add(p * 2 + 1, L, R, val);
    push(p);
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
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
    build(1, 1, cnt);
    for (int i = 1; i <= 2 * n; i++)
    {
        add(1, line[i].y1, line[i].y2 - 1, line[i].opt);
        ans += (line[i + 1].x - line[i].x) * tree[1].len;
    }
    printf("%lld", ans);
    return 0;
}
