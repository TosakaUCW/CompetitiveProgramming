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

const int MAXN = 2e5 + 5; // 模式串长度之和
typedef unsigned long long ull;

int tr[MAXN][26], fail[MAXN], tot = 0;
int e[MAXN], sum[MAXN];
vector<int> G[MAXN];
int ins(string s) {
    int u = 0;
    for (auto ch : s) {
        int c = ch - 'a';
        if (!tr[u][c])
            tr[u][c] = ++tot;
        u = tr[u][c];
    }
    return u;
}
void bfs() {
    std::queue<int> q;
    for (int c = 0; c < 26; c++)
        if (tr[0][c])
            q.push(tr[0][c]);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int c = 0; c < 26; c++)
            if (tr[u][c]) {
                fail[tr[u][c]] = tr[fail[u]][c];
                q.push(tr[u][c]);
            } else
                tr[u][c] = tr[fail[u]][c];
    }
}

void solve()
{
    
    int n = read();
    vector<int> can(n + 1);
    
    
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
    
    
    for (int j = 1; j <= n; j++) {
        string s, B; cin >> s >> B;
        // cout << s << ' ' << B << '\n';
        e[j] = ins(s);
        
        
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
    
    bfs();
    for (int u = 1; u <= tot; u++)
        G[fail[u]].push_back(u);
        
    int u = 0;
    for (auto ch : T) {
        int c = ch - 'a';
        u = tr[u][c], sum[u]++;
    }
    auto dfs = [&](int u, auto&& self) -> void {
        for (auto v : G[u]) {
            self(v, self);
            sum[u] += sum[v];
        }
    };
    dfs(0, dfs);
    
    // for (int i = 1; i <= n; i++)
    //     cout << sum[e[i]] << '\n';
    for (int i = 1; i <= n; i++)
        if (sum[e[i]] and can[i]) cout << i << ' ';
    puts("");
    
    
    for (int u = 0; u <= tot; u++)
    {
        G[fail[u]].clear();
        for (int j = 0; j < 26; j++)  tr[u][j] = 0;
        fail[u] = 0;
        sum[u] = 0;
        e[u] = 0;
        G[u].clear();
    } 
    // memset(fail, 0, sizeof fail);
    // memset(e, 0, sizeof e);
    // memset(sum, 0, sizeof sum);
    // memset(tr, 0, sizeof tr);
    
    tot = 0;
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