#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>

const int N = 200 + 5;

int cnt = 1, ans = 1 << 30;
std::string s, t, p[N], q[N];
int len[N][3];
std::map<std::string, bool> vis;

struct Node
{
    int tot;
    std::string x;
};

std::queue<Node> Q;

/*
void dfs(std::string x, int tot)
{
    int lenx = x.length();
    while (x[lenx - 1] == 0)
        lenx--;
    bool flag = true;
    if (lenx != lent)
        flag = false;
    for (int i = 0; i < lenx; i++)
        if (x[i] != t[i])
            flag = false;
    if (flag)
    {
        ans = std::min(ans, tot);
        // printf("\nans:%d  tot:%d\n", ans, tot);
        return;
    }
    if (tot > 10 or vis[x] or x == "")
        return;
    vis[x] = true;
    for (int i = 1; i <= cnt; i++)
    {
        int k = x.find(con[i].p);
        int lenq = con[i].q.length();
        int lenp = con[i].p.length();
        if (k == std::string::npos)
            continue;
        std::string new_x = "";
        for (int i = 0; i < k; i++)
            new_x += x[i];
        new_x += con[i].q;
        for (int i = k + lenp; i <= lenx; i++)
            new_x += x[i];
        // std::cout << x << ' ' << new_x << '\n';
        dfs(new_x, tot + 1);
    }
}
*/

void bfs()
{
    Q.push(Node{0, s});
    vis[s] = true;
    while (!Q.empty())
    {
        std::string x = Q.front().x;
        int tot = Q.front().tot;
        int lenx = x.length();
        Q.pop();
        if (tot > 10)
        {
            puts("NO ANSWER!");
            exit(0);
        }
        for (int i = 1; i <= cnt; i++)
        {
            if (x.find(p[i]) != -1)
                for (int k = x.find(p[i]); k < lenx and k != -1; k = x.find(p[i], k + 1))
                {
                    std::string new_x = x;
                    new_x.replace(k, len[i][1], q[i]);
                    if (new_x == t)
                    {
                        printf("%d", tot + 1);
                        exit(0);
                    }
                    if (!vis[new_x])
                    {
                        vis[new_x] = true;
                        Q.push(Node{tot + 1, new_x});
                    }
                }
        }
    }
}

int main()
{
    std::cin >> s >> t;
    len[0][1] = s.length(), len[0][2] = t.length();
    while (std::cin >> p[cnt] >> q[cnt])
        len[cnt][1] = p[cnt].length(), len[cnt][2] = q[cnt].length(), cnt++;
    --cnt;
    // dfs(s, 0);
    if (s == t)
        puts("0");
    else
        bfs();
    puts("NO ANSWER!");
    return 0;
}