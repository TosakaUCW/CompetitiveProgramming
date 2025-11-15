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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

mt19937_64 rng(20041019);
const int n = 1e6;
u64 hval[n + 1];
unordered_map<u64, int> rev;
void prepare() {
    for (int i = 1; i <= n; i++) {
        u64 x = rng();
        while (x == 0) x = rng();
        hval[i] = x;
        rev[x] = i;
    }
}

void solve() {
    string s; cin >> s;
    int n = 1e6;
    u64 sum = 0;;
    if (s == "resume") cin >> sum;

    int m = read();
    for (int i = 0; i < m; i++) {
        int x = read();
        sum ^= hval[x];

        if (sum == 0) {
            cout << "0\n";
        } else {
            auto it = rev.find(sum);
            if (it != rev.end()) {
                cout << it->second << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    if (s == "start") cout << sum << '\n';
}

signed main() {
    prepare();
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}