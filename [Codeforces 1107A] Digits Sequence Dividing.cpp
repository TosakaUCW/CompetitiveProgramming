#include <stdio.h>
#include <iostream>
#include <string>

const int N = 300;

int n, tot;
bool flag;
std::string s, ans[N];

bool cmp(std::string a, std::string b)
{
    int len = a.length();
    for (int i = 0; i < len; i++)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

void DFS(int depth, std::string last)
{
    if (depth == n - 1)
    {
        flag = true;
        return;
    }
    int len, last_len;
    len = last_len = last.length();
    std::string now = s.substr(depth + 1, len);
    if (cmp(last, now))
    {
        if (depth + len + 1 >= n)
            return;
        len++, now = s.substr(depth + 1, len);
    }
    while (depth + len < n and !flag)
    {
        DFS(depth + len, now);
        if (flag)
        {
            ans[++tot] = now;
            break;
        }
        len++, now = s.substr(depth + 1, len);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        flag = false;
        tot = 0;
        scanf("%d", &n);
        std::cin >> s;
        DFS(-1, "0");
        if (tot >= 2)
        {
            printf("YES\n%d\n", tot);
            for (int i = tot; i >= 1; i--)
                std::cout << ans[i] << " ";
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}