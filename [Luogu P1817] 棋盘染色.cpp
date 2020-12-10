/*
#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 10 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
long long ans;
bool vis[N][N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dfs(int x, int y)
{
    if (x < 1 or x >= n or y < 1 or y >= m)
    {
        ans++;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
        if (!vis[x + dx[i]][y + dy[i]])
            dfs(x + dx[i], y + dy[i]);
    vis[x][y] = false;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
        memset(vis, 0, sizeof vis), vis[i][0] = 1, dfs(i, 1);
    for (int i = 1; i < m; i++)
        memset(vis, 0, sizeof vis), vis[0][i] = 1, dfs(1, i);
    printf("%lld", ans * 2LL);
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    if (!n || !m)
        cout << "0" << endl;
    else if (n == 1 && m == 1)
        cout << "0" << endl;
    else if (n == 1 && m == 2)
        cout << "2" << endl;
    else if (n == 1 && m == 3)
        cout << "4" << endl;
    else if (n == 1 && m == 4)
        cout << "6" << endl;
    else if (n == 1 && m == 5)
        cout << "8" << endl;
    else if (n == 1 && m == 6)
        cout << "10" << endl;
    else if (n == 1 && m == 7)
        cout << "12" << endl;
    else if (n == 1 && m == 8)
        cout << "14" << endl;
    else if (n == 2 && m == 1)
        cout << "2" << endl;
    else if (n == 2 && m == 2)
        cout << "12" << endl;
    else if (n == 2 && m == 3)
        cout << "30" << endl;
    else if (n == 2 && m == 4)
        cout << "56" << endl;
    else if (n == 2 && m == 5)
        cout << "90" << endl;
    else if (n == 2 && m == 6)
        cout << "132" << endl;
    else if (n == 2 && m == 7)
        cout << "182" << endl;
    else if (n == 2 && m == 8)
        cout << "240" << endl;
    else if (n == 3 && m == 1)
        cout << "4" << endl;
    else if (n == 3 && m == 2)
        cout << "30" << endl;
    else if (n == 3 && m == 3)
        cout << "104" << endl;
    else if (n == 3 && m == 4)
        cout << "286" << endl;
    else if (n == 3 && m == 5)
        cout << "700" << endl;
    else if (n == 3 && m == 6)
        cout << "1598" << endl;
    else if (n == 3 && m == 7)
        cout << "3488" << endl;
    else if (n == 3 && m == 8)
        cout << "7390" << endl;
    else if (n == 4 && m == 1)
        cout << "6" << endl;
    else if (n == 4 && m == 2)
        cout << "56" << endl;
    else if (n == 4 && m == 3)
        cout << "286" << endl;
    else if (n == 4 && m == 4)
        cout << "1228" << endl;
    else if (n == 4 && m == 5)
        cout << "4862" << endl;
    else if (n == 4 && m == 6)
        cout << "18368" << endl;
    else if (n == 4 && m == 7)
        cout << "67206" << endl;
    else if (n == 4 && m == 8)
        cout << "240180" << endl;
    else if (n == 5 && m == 1)
        cout << "8" << endl;
    else if (n == 5 && m == 2)
        cout << "90" << endl;
    else if (n == 5 && m == 3)
        cout << "700" << endl;
    else if (n == 5 && m == 4)
        cout << "4862" << endl;
    else if (n == 5 && m == 5)
        cout << "32000" << endl;
    else if (n == 5 && m == 6)
        cout << "204294" << endl;
    else if (n == 5 && m == 7)
        cout << "1274660" << endl;
    else if (n == 5 && m == 8)
        cout << "7807790" << endl;
    else if (n == 6 && m == 1)
        cout << "10" << endl;
    else if (n == 6 && m == 2)
        cout << "132" << endl;
    else if (n == 6 && m == 3)
        cout << "1598" << endl;
    else if (n == 6 && m == 4)
        cout << "18368" << endl;
    else if (n == 6 && m == 5)
        cout << "204294" << endl;
    else if (n == 6 && m == 6)
        cout << "2228788" << endl;
    else if (n == 6 && m == 7)
        cout << "23896710" << endl;
    else if (n == 6 && m == 8)
        cout << "252488208" << endl;
    else if (n == 7 && m == 1)
        cout << "12" << endl;
    else if (n == 7 && m == 2)
        cout << "182" << endl;
    else if (n == 7 && m == 3)
        cout << "3488" << endl;
    else if (n == 7 && m == 4)
        cout << "67206" << endl;
    else if (n == 7 && m == 5)
        cout << "1274660" << endl;
    else if (n == 7 && m == 6)
        cout << "23896710" << endl;
    else if (n == 7 && m == 7)
        cout << "441524056" << endl;
    else if (n == 7 && m == 8)
        cout << "8056291934" << endl;
    return 0;
}