#include <stdio.h>
#include <algorithm>
#include <vector>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2.5e5 + 5;

int n, m;
std::vector<int> a[N], tmp, b;

bool judge()
{
    for (int i = 1; i <= n; i++)
    {
        int tot = 0, del = -1;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != tmp[j])
                tot++;
            if (tmp[j] == -1)
                del = j;
        }
        if (tot > 3)
            return false;
        if (tot == 3)
            if (del != -1)
                tmp[del] = a[i][del];
            else
                return false;
    }
    return true;
}

void print(std::vector<int> ans)
{
    puts("Yes");
    for (auto x : ans)
        printf("%d ", x == -1 ? 1919810 : x);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i].emplace_back(read());
    int max = 0, pos;
    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            if (a[1][j] != a[i][j])
                cnt++;
        if (cnt > max)
            max = cnt, pos = i;
    }
    if (max > 4)
        return puts("No"), 0;
    else if (max <= 2)
        print(a[1]);
    else
    {
        for (int i = 0; i < m; i++)
            if (a[1][i] != a[pos][i])
                b.emplace_back(i);
        for (int i = 0; i < b.size(); i++)
            for (int j = i + 1; j < b.size(); j++)
            {
                tmp = a[pos];
                tmp[b[i]] = -1, tmp[b[j]] = a[1][b[j]];
                if (judge())
                    return print(tmp), 0;
                tmp = a[pos];
                tmp[b[i]] = a[1][b[i]], tmp[b[j]] = -1;
                if (judge())
                    return print(tmp), 0;
            }
        puts("No");
    }
    return 0;
}