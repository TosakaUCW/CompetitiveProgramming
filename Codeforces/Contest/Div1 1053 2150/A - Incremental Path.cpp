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

void solve() {
    int n = read(), m = read();

    string s; cin >> s;
    vector<int> a(m);
    for (auto &x : a) x = read();

    auto b = a;

    int i = 0, x = 1;
    for (auto c : s) {
        if (c == 'A') {
            x++;
            b.eb(x);
        } else {
            while (i < m and a[i] <= x) {
                i++;
            }

            x++;

            while (i < m and a[i] == x) {
                x++;
                i++;
            }
            b.eb(x);

            x++;
            while (i < m and a[i] == x) {
                x++;
                i++;
            }
        }
    }

    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    cout << b.size() << '\n';
    for (auto x : b) {
        cout << x << " \n"[x == b.back()];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}