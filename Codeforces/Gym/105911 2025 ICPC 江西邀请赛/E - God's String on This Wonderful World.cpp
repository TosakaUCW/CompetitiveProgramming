#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;

void solve() {
    int n = read();
    int k = read();
    int q = read();
    string s; cin >> s; s = " " + s;

    vector<ull> freq(26);
    ull base = 199937;
    vector<ull> a(n + 1);
    for (int i = 1; i <= n; i++) {
        freq[s[i] - 'a']++;
        freq[s[i] - 'a'] %= k;
        for (auto f : freq) a[i] = a[i] * base + f;
    }

    auto b = a;
    ranges::sort(b);
    for (auto &x : a) x = ranges::lower_bound(b, x) - b.begin() + 1;

    vector<array<int, 3>> qry(q);
    for (int i = 0; i < q; i++) {
        qry[i][0] = read() - 1;
        qry[i][1] = read();
        qry[i][2] = i;
    }
    const int B = 450;
    ranges::sort(qry, [&](auto i, auto j) {
        if (i[0] / B != j[0] / B) { return i[0] / B < j[0] / B; }
        return (i[0] / B % 2 ? i[1] > j[1] : i[1] < j[1]);
    });

    vector<int> ans(q);
    vector<int> mp(n + 10);
    
    int l = 0, r = -1, res = 0;
    auto add = [&](int &x, int k) {
        res -= x * (x - 1);
        x += k;
        res += x * (x - 1);
    };
    for (auto [ql, qr, id] : qry) {
        while (l > ql) add(mp[a[--l]], +1);
        while (r < qr) add(mp[a[++r]], +1);
        while (l < ql) add(mp[a[l++]], -1);
        while (r > qr) add(mp[a[r--]], -1);

        ans[id] = res;
    }

    for (auto x : ans) cout << x / 2 << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}