#include <bits/stdc++.h>
using i64 = long long;
using i128  = __int128_t;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

struct SuffixArray {
    vector<int> sa, rank, height, log2, *st;
    int n;
    SuffixArray(const string &s) { buildSA(s); buildLCP(s); buildST(); }
    void buildSA(const string &s) {
        n = s.size();
        sa.resize(n); rank.resize(n); vector<int> tmp(n);
        for (int i = 0; i < n; ++i) sa[i] = i, rank[i] = s[i];
        for (int k = 1;; k <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = i + k < n ? rank[i + k] : -1;
                int rj = j + k < n ? rank[j + k] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            rank.swap(tmp);
            if (rank[sa.back()] == n - 1) break;
        }
    }
    void buildLCP(const string &s) {
        height.assign(n, 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            int r = rank[i];
            if (!r) continue;
            int j = sa[r - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
            height[r] = h;
            if (h) --h;
        }
    }
    void buildST() {
        int K = 1; while ((1 << K) <= n) ++K;
        st = new vector<int>[K];
        st[0] = height;
        for (int k = 1; k < K; ++k) {
            st[k].resize(n - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
        log2.resize(n + 1); log2[1] = 0;
        for (int i = 2; i <= n; ++i) log2[i] = log2[i >> 1] + 1;
    }
    int lcp(int i, int j) const {
        if (i == j) return n - i;
        int ri = rank[i], rj = rank[j];
        if (ri > rj) swap(ri, rj);
        int k = log2[rj - ri];
        return min(st[k][ri + 1], st[k][rj - (1 << k) + 1]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    SuffixArray SA(b);

    int mx = 0;
    for (int s = 1; s <= m - n; s++) {
        int l = SA.lcp(s, mx);

        if (l >= n) continue;

        char p = b[s + l], q = b[mx + l];
        if (a[l] == '0') {
            if (p > q) mx = s;
        } else {
            if (p < q) mx = s;
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans += (a[j] - '0') ^ (b[mx + j] - '0');
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}