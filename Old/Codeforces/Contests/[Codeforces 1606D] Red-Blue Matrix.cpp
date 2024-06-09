#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e6 + 5;
const int P = 998244353;
const int INF = 2147483647;

int n, m;
using std::vector;

void solve()
{
    n = read(), m = read();
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = read();
    vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&a](int x, int y)
              { return a[x][0] > a[y][0]; });
    vector<vector<int>> mxl(n, vector<int>(m, -INF));
    vector<vector<int>> mnr(n, vector<int>(m, INF));
    vector<int> mnl(m, INF);
    vector<int> mxr(m, -INF);

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
        {
            mxl[i][j] = a[idx[i]][j];
            if (i + 1 < n)
                mxl[i][j] = std::max(mxl[i][j], mxl[i + 1][j]);
            if (j - 1 >= 0)
                mxl[i][j] = std::max(mxl[i][j], mxl[i][j - 1]);
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            mnr[i][j] = a[idx[i]][j];
            if (i + 1 < n)
                mnr[i][j] = std::min(mnr[i][j], mnr[i + 1][j]);
            if (j + 1 < m)
                mnr[i][j] = std::min(mnr[i][j], mnr[i][j + 1]);
        }
    pii ans(-1, -1);
    // row : red [0, i] blue[i + 1, n)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mnl[j] = std::min(mnl[j], a[idx[i]][j]);
            if (j - 1 >= 0)
                mnl[j] = std::min(mnl[j], mnl[j - 1]);
        }
        for (int j = m - 1; j >= 0; j--)
        {
            mxr[j] = std::max(mxr[j], a[idx[i]][j]);
            if (j + 1 < m)
                mxr[j] = std::max(mxr[j], mxr[j + 1]);
        }
        for (int j = 0; j < m - 1; j++)
            if (mnl[j] > mxl[i + 1][j] and mxr[j + 1] < mnr[i + 1][j + 1])
                ans = {i, j};
    }
    if (ans.fi == -1)
        return puts("NO"), void();
    std::string res(n, ' ');
    for (int i = 0; i < n; i++)
        res[idx[i]] = i <= ans.fi ? 'R' : 'B';
    printf("YES\n%s %d\n", res.c_str(), ans.se + 1);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
/*
1.左边矩阵中颜色为红色的 a 的最小值大于颜色为蓝色的 a 的最大值；
2.右边矩阵中颜色为蓝色的 a 的最小值大于颜色为红色的 a 的最大值。
考虑到当你选左边的时候，假如这一行的 min 大于等于 之前红色的 min，那这行必然只能红色，否则红蓝均可
按 min 逆序排序，红色的必然是个前缀，剩下的后缀部分都是蓝色
枚举 k， 枚举红蓝分界点，判断合法即可
*/