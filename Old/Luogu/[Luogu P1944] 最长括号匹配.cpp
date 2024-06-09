#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>

const int N = 1e6 + 5;

int n, ans_val, L, R;
int ans, pos;
std::string str;
bool vis[N];
struct Node
{
    int val, pos;
};
std::stack<Node> S;

int main()
{
    std::cin >> str;
    n = str.length();
    for (int i = 0; i < n; i++)
        if (!S.empty() and (S.top().val == '(' and str[i] == ')' or S.top().val == '[' and str[i] == ']'))
            vis[S.top().pos] = vis[i] = true, S.pop();
        else
            S.push(Node{str[i], i});
    for (int i = 0; i < n; i++)
        if (!vis[i])
            ans = 0, pos = i + 1;
        else
        {
            ans++;
            if (ans > ans_val)
                L = pos, R = i, ans_val = ans;
        }
    for (int i = L; i <= R; i++)
        std::cout << str[i];
    return 0;
}