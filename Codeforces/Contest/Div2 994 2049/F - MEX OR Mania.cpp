#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
struct DSU {
    std::vector<int> f;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0); }
    int find(int x) { return f[x] != x ? f[x] = find(f[x]) : x; }
};
// mex(S) = or(S) + 1
// mex(S) <= max(S) + 1
// max(S) <= or(S) = mex(S) - 1
// max(S) + 1 <= mex(S)

// mex(S) = max(S) + 1
// max(S) = or(S)
void solve() {
    int n = read();
    int m = read();

    vector<int> a(n);
    vector<std::array<int, 2>> qry(m);
    for (auto &x : a) x = read();
    for (auto &[i, x] : qry) i = read() - 1, x = read();

    // for (auto [i, x] : qry) a[i] += x;

    DSU dsu(n);
    vector<int> L(n), R(n);
    vector<int> ans(m);

    for (int k = 0; k <= 30; k++) {
        int tar = 1LL << k;
        int lim = (1LL << k) - 1;
        
        for (auto [i, x] : qry) a[i] += x;

        dsu.init(n);
        std::iota(L.begin(), L.end(), 0);
        std::iota(R.begin(), R.end(), 0);
        vector<std::map<int, int>> mp(n);
        std::multiset<int> s;
        s.ep(0);

        auto myMerge = [&](int x, int y) -> bool {
            x = dsu.find(x), y = dsu.find(y);
            if (x == y) return false;
            if (mp[x].size() < mp[y].size()) swap(x, y);
            if (mp[x].size() == tar) s.erase(s.find(R[x] - L[x] + 1));
            if (mp[y].size() == tar) s.erase(s.find(R[y] - L[y] + 1));

            dsu.f[y] = x;
            for (auto [num, cnt] : mp[y]) {
                mp[x][num] += cnt;
                // cerr << "!";
            }

            mp[y].clear();

            L[x] = min(L[x], L[y]);
            R[x] = max(R[x], R[y]);

            if (mp[x].size() == tar) s.ep(R[x] - L[x] + 1);
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (a[i] > lim) continue;

            if (!k) s.ep(1);
            mp[i][a[i]] = 1;
            if (i > 0 and a[i - 1] <= lim) myMerge(i - 1, i);
        }

        for (int i = m - 1; i >= 0; i--) {
            ans[i] = max(ans[i], *--s.end());

            auto [p, x] = qry[i];
            auto &val = a[p];
            val -= x;

            if (i == 0 or val > lim) continue;

            int fp = dsu.find(p);

            if (val + x <= lim) {
                if (!--mp[fp][val + x]) {
                    if (mp[fp].size() == tar) {
                        s.erase(s.find(R[fp] - L[fp] + 1));
                    }
                    mp[fp].erase(val + x);
                }
            }
            mp[fp][val]++;
            if (mp[fp].size() == tar and mp[fp][val] == 1) {
                s.ep(R[fp] - L[fp] + 1);
            }
            if (p - 1 >= 0 and a[p - 1] <= lim) myMerge(p - 1, p);
            if (p + 1 < n and a[p + 1] <= lim) myMerge(p + 1, p);
        }
    }

    for (auto x : ans) printf("%d\n", x);
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
