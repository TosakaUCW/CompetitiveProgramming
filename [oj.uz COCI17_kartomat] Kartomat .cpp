#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n;
std::string s;

int trie[N][26];
int nodecnt;

int main()
{
    for (int T = read(); T--;)
    {
        std::cin >> s, n = s.size();
        for (int i = 0, p = 0; i < n; i++)
            if (trie[p][s[i] - 'A'])
                p = trie[p][s[i] - 'A'];
            else
                p = trie[p][s[i] - 'A'] = ++nodecnt;
    }
    std::cin >> s, n = s.size();
    int p = 0;
    for (int i = 0; i < n and trie[p][s[i] - 'A']; i++)
        p = trie[p][s[i] - 'A'];
    printf("***");
    for (int i = 0; i < 26; i++)
    {
        putchar(trie[p][i] ? char(i + 'A') : '*');
        if (i == 4 or i == 12 or i == 20)
            puts("");
    }
    printf("***");

    return 0;
}