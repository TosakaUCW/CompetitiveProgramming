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

const int N = 5e4 + 5;

void solve() {
    int n = read();
    string a, b; cin >> a >> b;
    a = " " + a, b = " " + b;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (a[i] == '0' ? -1 : 1);
    }

    vector<int> p(n + 1);
    ranges::iota(p, 0);
    ranges::sort(p, [&](int i, int j) {
        if (s[i] == s[j]) return i < j;
        return s[i] > s[j];
    });

    bitset<N> bad, vis, mask;
    for (int i = 1; i <= n; i++) mask.set(i);

    int tg = n + 1;
    for (int i : p) {
        if (i) {
            if (b[i] == '1') {
                bad |= (vis >> (n - i));
                if (s[i] <= 0) tg = min(tg, i + 1);
            } else {
                bad |= ((vis ^ mask) >> (n - i));
                if (s[i] > 0) tg = min(tg, i + 1);
            }
        }
        vis[n - i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (bad[i] or i >= tg) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
    cout << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}