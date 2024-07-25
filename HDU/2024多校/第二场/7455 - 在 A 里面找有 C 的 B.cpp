#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

typedef unsigned long long ull;

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        Node() : len{0}, link{0}, next{} {}
    };
    std::vector<Node> t;
    AhoCorasick() { init(); }
    void init() { t.assign(2, Node()), t[0].next.fill(1), t[0].len = -1; }
    int newNode() { t.emplace_back(); return t.size() - 1; }
    int add(const std::string &a) {
        int p = 1;
        for (auto c : a) {
            int x = c - 'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        return p;
    }
    void work() {
        std::queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            
            for (int i = 0; i < ALPHABET; i++)
                if (t[x].next[i] == 0)
                    t[x].next[i] = t[t[x].link].next[i];
                else
                    t[t[x].next[i]].link = t[t[x].link].next[i],
                    q.push(t[x].next[i]);
        }
    }
    int next(int p, int x) { return t[p].next[x]; }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};


void solve()
{
    int n = read();
    vector<int> can(n + 1);
    
    AhoCorasick ac;
    
    string T, C;
    cin >> T >> C;
    
    int len = C.size();
    C = " " + C;
    ull bas = 13331;
    vector<ull> hC(len + 1), pow(len + 1);
    pow[0] = 1;
    for (int i = 1; i <= len; i++) pow[i] = pow[i - 1] * bas;
    for (int i = 1; i <= len; i++) hC[i] = hC[i - 1] * bas + C[i] - 'a';
    ull HASH = hC[len];
    
    
    vector<int> end(n);
    for (int j = 1; j <= n; j++) {
        string s, B; cin >> s >> B;
        end[j - 1] = ac.add(s);
        
        int m = B.size();
        vector<ull> hB(B.size() + 1);
        B = " " + B;
        for (int i = 1; i <= m; i++) hB[i] = hB[i - 1] * bas + B[i] - 'a';
        
        for (int i = 1; i + len - 1 <= m; i++)
        {
            ull x = (hB[i + len - 1] - hB[i - 1] * pow[len]);
            if (x == HASH) can[j] = 1;
        }
    }
    ac.work();
    
    int p = 1;
    std::vector<int> f(ac.size());
    for (auto c : T) p = ac.next(p, c - 'a'), f[p]++;
    std::vector<std::vector<int>> adj(ac.size());
    for (int i = 2; i < ac.size(); i++) adj[ac.link(i)].push_back(i);
    auto dfs = [&](auto self, int x) -> void {
        for (auto y : adj[x]) self(self, y), f[x] += f[y];
    };
    dfs(dfs, 1);
    
    for (int i = 1; i <= n; i++)
        if (f[end[i - 1]] and can[i]) cout << i << " ";
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}