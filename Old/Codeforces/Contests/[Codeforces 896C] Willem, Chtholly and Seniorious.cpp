#include <stdio.h>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>

using std::pair;
using std::set;
using std::vector;

typedef long long ll;
#define IT std::set<Node>::iterator
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e5;

int n, m;
ll seed, vmax;
ll a[N + 5];

struct Node
{
    int l, r;
    mutable ll v;
    Node(int L, int R = -1, ll V = 0) : l(L), r(R), v(V) {}
    bool operator<(const Node &o) const
    {
        return l < o.l;
    }
};

ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

std::set<Node> s;

IT split(int pos)
{
    IT it = s.lower_bound(Node(pos));
    if (it != s.end() and it->l == pos)
        return it;
    it--;
    int L = it->l;
    int R = it->r;
    ll V = it->v;
    s.erase(it);
    s.insert(Node(L, pos - 1, V));
    return s.insert(Node(pos, R, V)).first;
}

void assign(int l, int r, int val = 0)
{
    IT itl = split(l);
    IT itr = split(r + 1);
    s.erase(itl, itr);
    s.insert(Node(l, r, val));
}

void add(int l, int r, ll val = 1)
{
    IT itl = split(l);
    IT itr = split(r + 1);
    for (; itl != itr; ++itl)
        itl->v += val;
}

ll rank(int l, int r, int k)
{
    vector<pair<ll, int>> vp;
    IT itl = split(l);
    IT itr = split(r + 1);
    vp.clear();
    for (; itl != itr; itl++)
        vp.push_back(pair<ll, int>(itl->v, itl->r - itl->l + 1));
    std::sort(vp.begin(), vp.end());
    for (vector<pair<ll, int>>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        k -= it->second;
        if (k <= 0)
            return it->first;
    }
    return -1LL;
}

ll sum(int l, int r, int ex, int p)
{
    IT itl = split(l);
    IT itr = split(r + 1);
    ll res = 0;
    for (; itl != itr; itl++)
        res = (res + (itl->r - itl->l + 1) * pow(itl->v, ex, p)) % p;
    return res;
}

ll rnd()
{
    ll res = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return res;
}

int main()
{
    scanf("%d%d%lld%lld", &n, &m, &seed, &vmax);
    Rep(i, 1, n)
    {
        a[i] = (rnd() % vmax) + 1;
        s.insert(Node(i, i, a[i]));
    }
    s.insert(Node(n + 1, n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        int op = int(rnd() % 4) + 1;
        int l = int(rnd() % n) + 1;
        int r = int(rnd() % n) + 1;
        if (l > r)
            std::swap(l, r);
        int x, y;
        if (op == 3)
            x = int(rnd() % (r - l + 1)) + 1;
        else
            x = int(rnd() % vmax) + 1;
        if (op == 4)
            y = int(rnd() % vmax) + 1;
        if (op == 1)
            add(l, r, ll(x));
        else if (op == 2)
            assign(l, r, ll(x));
        else if (op == 3)
            printf("%lld\n", rank(l, r, x));
        else
            printf("%lld\n", sum(l, r, x, y));
    }
    return 0;
}