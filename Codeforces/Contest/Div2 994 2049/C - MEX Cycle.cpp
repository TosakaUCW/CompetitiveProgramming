#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

int getmex(const vector<int>& a) {
    std::unordered_set<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.find(mex) != s.end()) {
        mex++;
    }
    return mex;
}

void solve() {
    int n = read();
    int x = read(), y = read();

    vector<vector<int>> g(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int prev = (i == 1) ? n : i - 1;
        int next = (i == n) ? 1 : i + 1;
        g[i].eb(prev);
        g[i].eb(next);
    }
    
    bool f = false;
    for (auto v : g[x]) {
        if(v == y) {
            f = true;
            break;
        }
    }
    if (!f) g[x].eb(y), g[y].eb(x);
    
    vector<int> a(n + 1);
    
    std::queue<int> q;
    vector<bool> inq(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        q.ep(i);
        inq[i] = true;
    }
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        vector<int> t;
        for (auto v : g[u]) {
            t.push_back(a[v]);
        }
        int mex = getmex(t);
        
        if (a[u] != mex) {
            a[u] = mex;
            for (auto v : g[u]) {
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    
    f = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> t;
        for(auto v : g[i]) {
            t.push_back(a[v]);
        }
        int mex = getmex(t);
        if (a[i] != mex){
            f = 0;
            break;
        }
    }
    
    if (!f) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    } 
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
