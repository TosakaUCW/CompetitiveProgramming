#include <memory.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

const int N = 1e5 + 5;

int n;

struct Node
{
    int s[N];
    Node() { memset(s, 0, sizeof s); }
    void operator=(std::string str)
    {
        s[0] = str.size();
        for (int i = s[0] - 1; i >= 0; i--)
            s[s[0] - i] = (str[i] >= '0' and str[i] <= '9') ? str[i] - '0' : str[i] - 'A' + 10;
        while (s[s[0]] == 0)
            s[0]--;
    }
    void operator=(int b)
    {
        memset(s, 0, sizeof s);
        while (b > 0)
            s[++s[0]] = b % 10, b /= 10;
    }
    Node friend operator+(Node a, Node b)
    {
        Node c;
        c.s[0] = std::max(a.s[0], b.s[0]);
        for (int i = 1; i <= c.s[0]; i++)
        {
            c.s[i] += a.s[i] + b.s[i];
            if (c.s[i] >= n)
                c.s[i + 1] += c.s[i] / n, c.s[i] %= n;
        }
        if (c.s[c.s[0] + 1] > 0)
            c.s[0]++;
        return c;
    }
    Node reverse()
    {
        Node c;
        for (int i = 1; i <= s[0]; i++)
            c.s[i] = s[s[0] - i + 1];
        return c;
    }
    bool check()
    {
        for (int i = 1; i <= s[0]; i++)
            if (s[i] != s[s[0] - i + 1])
                return false;
        return true;
    }
    void print()
    {
        for (int i = s[0]; i >= 1; i--)
            printf("%d", s[i]);
        puts("");
    }
} a, b;

int main()
{
    std::string x;
    std::cin >> n >> x;
    a = x;
    b = a.reverse();
    if (a.check())
    {
        puts("STEP=0");
        return 0;
    }
    for (int i = 1; i <= 30; i++)
    {
        Node c = a + b;
        if (c.check())
        {
            printf("STEP=%d", i);
            return 0;
        }
        a = c;
        b = c.reverse();
    }
    puts("Impossible!");
    return 0;
}