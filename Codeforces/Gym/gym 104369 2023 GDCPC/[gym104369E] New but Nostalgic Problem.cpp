#include <bits/stdc++.h>
// #define int long long
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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, ncnt;
int siz[N], tot[N], ch[N][26];
int newnode()
{
    ncnt++;
    siz[ncnt] = tot[ncnt] = 0;
    memset(ch[ncnt], 0, sizeof ch[ncnt]);
    return ncnt;
}
void solve()
{
    ncnt = 0, newnode();
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        int now = 1; tot[now]++;
        for (auto x : s)
        {
            int &c = ch[now][x - 97];
            if (!c) c = newnode();
            now = c, tot[now]++;
        }
        siz[now]++;
    }

    int now = 1;
    while (1)
    {
        int t = siz[now];
        for (int i = 0; i < 26; i++)
            if (tot[ch[now][i]]) t++;
        if (t >= k)
        {
            puts(now == 1 ? "EMPTY" : "");
            return;
        }

        for (int i = 0; i < 26; i++)
            if (tot[ch[now][i]])
            {
                t += tot[ch[now][i]] - 1;
                if (t >= k)
                {
                    k -= t - tot[ch[now][i]];
                    now = ch[now][i];
                    printf("%c", i + 97);
                    break;
                }
            }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}