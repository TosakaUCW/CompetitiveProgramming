#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
const int k = 1500;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    bool hasDup = false;
    for (int i = 0; i + 1 < n; i++) if (a[i] == a[i + 1]) hasDup = 1;
    if (hasDup or n > k) { cout << "YES\n"; return; }

    bool found = false;
    unordered_map<int, pii> mp;

    for(int i = 0; i < n and !found; i++) {
        for(int j = i + 1; j < n and !found; j++) {
            int s = a[i] + a[j];
            if (mp.find(s) == mp.end()) {
                mp[s] = {i, j};
            } else {
                auto [p, q] = mp[s]; 
                if (p != i and p != j and q != i and q != j) {
                    found = 1;
                }
            }
        }
    }

    cout << (found ? "YES\n" : "NO\n");
    // cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}