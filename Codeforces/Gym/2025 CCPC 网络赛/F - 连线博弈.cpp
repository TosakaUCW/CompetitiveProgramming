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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int _sg[5000];
int sg(int x) { 
    int t = (x - 100) / 34;
    t = max(t, 0ll);
    return _sg[x - (t * 34)];
}

void solve() {
    int n = read(), m = read();

    map<int, u64> diff;
    while (m--) {
        int l = read(), r = read();

        auto x = rnd();
        diff[l] ^= x;
        diff[r] ^= x;
    }

    map<int, u64> a;
    diff[n] = 0;
    u64 sum = 0;
    for (int las = -1; auto [i, val] : diff) {
        a[sum] += i - las - 1;
        sum ^= val;
        las = i;
    }

    int ans = 0;
    for (auto [_, x] : a) {
        ans ^= sg(x);
        // debug(x);
    }
    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    for (int i = 1; i <= 200; i++) {
        _sg[i] = -1;
    }
    _sg[0] = 0;
    _sg[1] = 0;
    _sg[2] = 1;
    _sg[3] = 1;
    for (int n = 2; n <= 200; n++) {
        set<int> st;
        for (int i = 0; i <= n - 2; i++) {
            int j = n - 2 - i;
            st.insert(_sg[i] ^ _sg[j]);
        }

        int mex = 0;
        for (auto s : st) {
            if (s != mex) break;
            mex++;
        }
        _sg[n] = mex;
    }

    // for (int i = 0; i < 200; i++) {
    //     cout << _sg[i] << " ";
    // }

    for (int T = read(); T--; solve());
    return 0;
}