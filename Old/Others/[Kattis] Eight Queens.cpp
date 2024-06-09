#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
bool flag;
std::string s[8];
struct Node { int x, y; };
std::vector<Node> a;
bool judge(Node a, Node b) { return a.x == b.x or a.y == b.y or a.x + a.y == b.x + b.y or a.x - a.y == b.x - b.y; }
signed main()
{
    for (int i = 0; i < 8; i++)
        std::cin >> s[i];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (s[i][j] == '*')
                a.emplace_back(Node{i, j});
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++)
            flag |= judge(a[i], a[j]);
    puts(flag ? "invalid" : "valid");
    return 0;
}