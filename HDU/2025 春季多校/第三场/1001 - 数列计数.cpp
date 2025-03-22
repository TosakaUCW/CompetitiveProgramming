#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

int f[32][2];

int dp(int pos, bool less, int a, int L) {
    if (pos < 0) return 1;
    if (f[pos][less] != -1) {
        return f[pos][less];
    }
    int bitA = (a >> pos) & 1;
    int bitL = (L >> pos) & 1;
    int res = 0;
    int upperB = bitA == 1 ? 1 : 0;
    for (int bitB = 0; bitB <= upperB; bitB++) {
        if (!less && bitB > bitL) {
            continue;
        }
        
        bool nextLess = less || (bitB < bitL);
        
        res += dp(pos - 1, nextLess, a, L);
    }
    
    f[pos][less] = res;
    return res;
}

int count(int a, int L) {
    for (int i = 0; i < 32; i++) f[i][0] = f[i][1] = -1;
    return dp(31, false, a, L);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> L(n);
    for (auto &x : L) cin >> x;

    i64 P = 998244353;
    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        i64 res = count(a[i], L[i]);
        ans = (ans * res) % P;
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    // int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}
