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

int ask(vector<int> S, int x) {
    cout << "? " << x << " " << S.size() << ' ';
    for (auto x : S) cout << x << ' ';
    cout << endl;
    return read();
}

vector<int> range(int l, int r) {
    vector<int> res;
    for (int i = l; i <= r; i++) {
        res.eb(i);
    }
    return res;
}

int go(int l, int r, vector<int> vals, vector<int> waste) {
    if (l == r) return vals.back();

    int len = (r - l + 1) / 2;
    int mid = l + len - 1;

    vector<int> vl = range(l, mid);
    vector<int> vr = range(mid + 1, r);

    int siz = mid - l + 1;
    vector<int> waste_l, waste_r;

    for (auto x : waste) {
        if (ask(vl, x)) {
            waste_l.eb(x);
        } else {
            waste_r.eb(x);  
        } 
    }

    vector<int> vals_l, vals_r;

    for (auto x : vals) {
        int r1 = ask(vl, x);
        int r2 = ask(vr, x);

        if (r1 and r2) {
            waste_l.eb(x);
            waste_r.eb(x);
        } else if (r1 and !r2) {
            vals_l.eb(x);
        } else if (!r1 and r2) {
            vals_r.eb(x);
        }
    }

    siz -= waste_l.size();

    if (siz & 1) {
        return go(l, mid, vals_l, waste_l);
    } else {
        return go(mid + 1, r, vals_r, waste_r);
    }
};

void solve() {
    int n = read();
    int ans = go(1, 2 * n - 1, range(1, n), {});
    cout << "! " << ans << endl;
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}