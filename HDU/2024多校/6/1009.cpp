#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::cerr;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}


struct node {
    i64 pos, rad;
    bool friend operator < (node A, node B) {
        return A.pos < B.pos;
    }
};
i64 mergetime(node a, node b) {
    return (abs(a.pos - b.pos) - (a.rad + b.rad) + 3) / 4;
}
node merge(node a, node b) {
    if (a.pos > b.pos) std::swap(a, b);
    i64 t = mergetime(a, b);
    i64 l = a.pos - (a.rad + 2 * t);
    i64 r = b.pos + (b.rad + 2 * t);
    return {(l + r) / 2, (r - l) / 2 - 2 * t};
}
struct event {
    // type: 0 mrg | 1 del | 2 qry
    i64 type, t, x, y;
    bool friend operator < (event A, event B) {
        if (A.t != B.t) return A.t < B.t;
        if (A.type != B.type) return A.type < B.type;
        if (A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    } 
};
event mergeevent(node a, node b) {
    return {0, mergetime(a, b), a.pos, b.pos};
}

void solve() {
    int m = read(), q = read();

    std::set<node> nds;
    nds.insert({0, 1});
    std::set<event> es;

    for (int t, l, r; m--; ) {
        t = read(), l = read(), r = read();
        es.insert({1, t, 2 * l - 1, 2 * r + 1});
    }
    for (int t; q--; ) {
        t = read();
        es.insert({2, t});
    }

    i64 radsum = 1;

    for (auto [type, t, l, r] : es) {
        if (type == 1) {
            // DEL
            auto it = nds.lower_bound({l});
            if (it != nds.begin()) it--;

            while (it != nds.end()) {
                node nd = *it;

                i64 ndl = nd.pos - (nd.rad + 2 * t);
                i64 ndr = nd.pos + (nd.rad + 2 * t);

                if (ndl >= r or ndr <= l) {
                    if (it->pos >= r) break;

                    it++; continue;
                }

                
            }

        }
        if (type == 0) {
            // MERGE
            auto it = nds.lower_bound({l});

            node lnd = *it;
            it = nds.erase(it);
            radsum -= lnd.rad;

            node rnd = *it;
            it = nds.erase(it);
            radsum -= rnd.rad;

            node nd = merge(lnd, rnd);

            if (it != nds.begin()) {
                auto pre = prev(it);
                es.erase(mergeevent(*pre, lnd));
                es.insert(mergeevent(*pre, nd));
            }
            if (it != nds.end()) {
                es.erase(mergeevent(rnd, *it));
                es.insert(mergeevent(nd, *it));
            }
            nds.insert(nd);
            radsum += nd.rad;
        }
        if (type == 2) {
            //QUERY
            cout << radsum + 2 * t * nds.size() << " ";
        }
    }

    cout << '\n';
}

/*
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}