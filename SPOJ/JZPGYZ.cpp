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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct SAM {
    // static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        // std::array<int, ALPHABET_SIZE> next;
        map<int, int> next;
        Node() : len{}, link{}, next{} {}
    };
    std::vector<Node> t;
    SAM() { init(); }
    void init() {
        t.assign(2, Node());
        // t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (p == 0) return 1;
        
        if (t[p].next.count(c)) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next.count(c)) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }
    int next(int p, int x) { return t[p].next[x]; }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};

void solve() {
    int n = read();
    int q = read();
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    SAM sam;
    vector<int> endpos;
    for (const auto &s : a) {
        int p = 1; 
        for (auto ch : s) {
            p = sam.extend(p, ch);
            endpos.eb(p);
        }    
    }

    int m = sam.size();
    vector<int> vis(sam.size(), -1);
    vector<int> sz(sam.size());

    int i = 0; 
    for (auto s : a) {
        int p = 1; 
        for (auto ch : s) {
            p = sam.next(p, ch);

            for (int now = p; now and vis[now] != i; now = sam.link(now)) {
                vis[now] = i;
                sz[now]++;
            }
        }
        i++;
    }

    while (q--) {
        string s; cin >> s;
        int p = 1;
        bool f = 1;
        for (auto ch : s) {
            if (!sam.t[p].next.count(ch)) {
                f = 0;
                break;
            }
            p = sam.next(p, ch);
        }

        int res = f ? sz[p] : 0;
        cout << res << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}