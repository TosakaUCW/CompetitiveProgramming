#include <memory.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

const int N = 1e4 + 5;

long long k, x;

struct Node
{
    int s[N];
    Node() { memset(s, 0, sizeof s); }
    void operator=(std::string str)
    {
        s[0] = str.size();
        for (int i = s[0] - 1; i >= 0; i--)
            s[s[0] - i] = str[i] - '0';
        while (s[s[0]] == 0)
            s[0]--;
    }
    void operator=(long long b)
    {
        memset(s, 0, sizeof s);
        while (b > 0)
            s[++s[0]] = b % 10, b /= 10;
    }
    bool friend operator<(Node a, Node b)
    {
        if (a.s[0] != b.s[0])
            return a.s[0] < b.s[0];
        for (int i = a.s[0]; i >= 1; i--)
            if (a.s[i] != b.s[i])
                return a.s[i] < b.s[i];
        return false;
    }
    bool friend operator>(Node a, Node b) { return !(a < b); }
    bool friend operator==(Node a, Node b) { return !(a < b) and !(a > b); }
    Node friend operator+(Node a, Node b)
    {
        Node c;
        c.s[0] = std::max(a.s[0], b.s[0]);
        for (int i = 1; i <= c.s[0]; i++)
        {
            c.s[i] += a.s[i] + b.s[i];
            if (c.s[i] >= 10)
                c.s[i + 1] += c.s[i] / 10, c.s[i] %= 10;
        }
        if (c.s[c.s[0] + 1] > 0)
            c.s[0]++;
        return c;
    }
    Node friend operator-(Node a, Node b)
    {
        Node c;
        c.s[0] = std::max(a.s[0], b.s[0]);
        for (int i = 1; i <= c.s[0]; i++)
        {
            c.s[i] = a.s[i] - b.s[i];
            if (c.s[i] < 0)
                c.s[i] += 10, a.s[i + 1]--;
        }
        while (c.s[c.s[0]] == 0 and c.s[0] > 1)
            c.s[0]--;
        return c;
    }
    Node friend operator*(Node a, Node b)
    {
        Node c;
        c.s[0] = a.s[0] + b.s[0] - 1;
        for (int i = 1; i <= a.s[0]; i++)
            for (int j = 1; j <= b.s[0]; j++)
                c.s[i + j - 1] += a.s[i] * b.s[j];
        for (int i = 1; i <= c.s[0]; i++)
            c.s[i + 1] += c.s[i] / 10, c.s[i] %= 10;
        if (c.s[c.s[0] + 1] > 0)
            c.s[0]++;
        return c;
    }
    Node friend operator/(Node a, Node b)
    {
        Node c, d;
        d = 10;
        c.s[0] = a.s[0] - b.s[0] + 2;
        for (int i = c.s[0]; i >= 1; i--)
        {
            int tmp = i - 1;
            Node k = b;
            while (tmp >= 1)
                k = k * d, tmp--;
            while (a > k)
            {
                a = a - k;
                c.s[i]++;
            }
        }
        while (c.s[c.s[0]] == 0 and c.s[0] > 1)
            c.s[0]--;
        return c;
    }
    Node friend operator%(Node a, Node b)
    {
        Node c;
        c = a - a / b * b;
        return c;
    }
    void print()
    {
        for (int i = s[0]; i >= 1; i--)
            printf("%d", s[i]);
        puts("");
    }
} ans, ten, xx;

int main()
{
    ten = 10;
    scanf("%lld%lld", &k, &x);
    xx = x;
    ans.s[0] = k + 1, ans.s[k + 1] = 1;
    ans = ans + xx;
    ans.print();
    return 0;
}