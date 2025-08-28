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

int ask(const auto &a) {
    cout << "? " << a.size();
    for (int x : a) cout << " " << x;
    cout << endl;
    int res; cin >> res; return res;
}

void solve() {
    const int N = 11343;
    const int B = 116;
    int r1 = ask(vector(N, B));

    int ans;

    if (r1 == 0) {
        int r2 = ask(vector(B * B, 1));

        ans = (B * B + r2 - 1) / r2;
    } else {
        int L = B * ((N - 1) / r1 + 1);
        int R = B * ((N - 1) / (r1 - 1) + 1) - 1;
        R = min(R, 100000LL);

        if (L == R) {
            cout << "! " << L << '\n';
            return;
        }

        vector<int> qry;
        for (int i = 1; i <= R - L; i++) {
            qry.eb(L); qry.eb(i);
        }

        int r2 = ask(qry);
        ans = 2 * R - L - r2;
    }
    
    cout << "! " << ans << endl;
}

signed main() {
    // freopen("D.in", "r", stdin);
    // freopen("D.out", "w", stdout);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}