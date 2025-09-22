#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

vector<int> getFail(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
vector<pii> kmp(string s, string t) {
    int n = s.size();
    int m = t.size();
    auto fail = getFail(s);
    vector<pii> pos;
    if (s == "") pos.eb(0, 0);
    for (int i = 0, j = 0; i < m; i++) {
        while (j and t[i] != s[j]) j = fail[j];
        if (t[i] == s[j]) j++;
        if (j == n) {
            pos.eb(i - j + 1, i + 1);
            j = fail[j];
        }
    }
    return pos;
}

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    if (s == string(n, '*')) {
        cout << (m + 1) * m / 2;
        return;
    }

    vector<string> ss;
    if (s[0] == '*') ss.eb("");
    for (int l = 0, r = 0; r <= n; r++) {
        if (r == n or s[r] == '*') {
            string tmp = s.substr(l, r - l);
            if (tmp != "") ss.eb(tmp);
            l = r + 1;
        }
    }
    if (s.back() == '*') ss.eb("");

    // debug(ss);

    int k = ss.size();
    vector<vector<pii>> pos(k);
    vector next(k, vector(m + 1, pii{inf, inf}));

    for (int i = 0; i < k; i++) {
        auto s = ss[i];

        pos[i] = kmp(s, t);

        auto &nex = next[i];
        for (auto [l, r] : pos[i]) {
            nex[l] = {l, r};
        }
        for (int j = m - 1; j >= 0; j--) {
            nex[j] = min(nex[j], nex[j + 1]);
        }
    }

    vector<int> cnt(m + 1);
    for (auto [l, r] : pos.back()) {
        cnt[l]++;
    }
    if (k > 1) {
        for (int i = m - 1; i >= 0; i--) {
            cnt[i] += cnt[i + 1];    
        }    
    }
    
    // debug(ss[0]);
    // debug(pos[0]);

    int ans = 0;
    for (auto [l, r] : pos[0]) {
        for (int i = 1; i < k; i++) {
            if (l > m) break;
            tie(l, r) = next[i][r];
        }
        // debug(l);
        if (l > m) continue;

        ans += cnt[l];
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}