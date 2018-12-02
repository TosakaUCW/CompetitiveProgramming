// luogu-judger-enable-o2
#include <stdio.h>
#include <algorithm>
#include <queue>

using std::priority_queue;

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e5;
const int LOG2N = 19;

int n, m, L, R;
ll ans, sum[N + 5];

struct SparseTable
{
    int log2[N + 5], st[N + 5][LOG2N + 5];
    void init()
    {
        log2[1] = 0;
        Rep(i, 2, n)
            log2[i] = log2[i / 2] + 1;
        Rep(i, 1, n)
            st[i][0] = i;
        Rep(j, 1, log2[n])
            Rep(i, 1, n - (1 << (j - 1)))
            {
                int x = st[i][j - 1];
                int y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = sum[x] > sum[y] ? x : y;
            }
    }
    int query(int l, int r)
    {
        int k = log2[r - l + 1];
        int x = st[l][k];
        int y = st[r - (1 << k) + 1][k];
        return sum[x] > sum[y] ? x : y;
    }
} rmq;

struct Node
{
    int k, l, r, pos;
    Node() {}
    Node(int k, int l, int r) : k(k), l(l), r(r), pos(rmq.query(l, r)) {}
    friend bool operator<(const Node &a, const Node &b)
    {
        return sum[a.pos] - sum[a.k - 1] < sum[b.pos] - sum[b.k - 1];
    }
};

priority_queue<Node> q;

int main()
{
    scanf("%d%d%d%d", &n, &m, &L, &R);
    Rep(i, 1, n)
    {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    rmq.init();
    Rep(i, 1, n)
    {
        if (i + L - 1 <= n)
            q.push(Node(i, i + L - 1, std::min(i + R - 1, n)));
    }
    while (m--)
    {
        int k = q.top().k;
        int l = q.top().l;
        int r = q.top().r;
        int pos = q.top().pos;
        q.pop();
        ans += sum[pos] - sum[k - 1];
        if (l != pos)
            q.push(Node(k, l, pos - 1));
        if (pos != r)
            q.push(Node(k, pos + 1, r));
    }
    printf("%lld", ans);
    return 0;
}
