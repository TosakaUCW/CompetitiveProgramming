#include <stdio.h>
#include <iostream>
#include <string>

int n, L, R, tot, ans;
std::string str;

int main()
{
    std::cin >> n >> str;
    for (int i = 0; i < n; i++)
        if (str[i] == '(')
            tot++, L++;
        else
            R++, tot > 0 ? tot--, ans += 2 : 0;
    return puts((L != R or (ans != n and ans != n - 2)) ? "No" : "Yes"), 0;
}