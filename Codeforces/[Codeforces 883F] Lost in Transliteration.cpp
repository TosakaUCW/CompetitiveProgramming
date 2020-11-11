#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <string>
#include <map>

const int N = 4e2 + 5;

int n, ans;
std::map<std::string, bool> map;

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

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        std::string s, t = "";
        std::cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++)
            if (s[i] == 'u')
                t += "oo";
            else if (s[i] == 'h')
            {
                int len = t.length() - 1;
                while (t[len] == 'k')
                    len--;
                t = t.substr(0, len + 1) + 'h';
            }
            else
                t += s[i];
        ans += !map[t], map[t] = true;
    }
    return printf("%d", ans), 0;
}