#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

const int N = 1e4 + 5;

int n, size, ans;
int L[2][N], R[2][N];
std::string s;

int idx(char c) { return c == 'r' ? 0 : 1; };

int main()
{
    std::cin >> n >> s;
    s += s;
    size = n * 2;
    for (int i = 1; i < size; i++)
        if (s[i - 1] != 'w')
            L[idx(s[i - 1])][i] = L[idx(s[i - 1])][i - 1] + 1;
        else
            L[0][i] = L[0][i - 1] + 1, L[1][i] = L[1][i - 1] + 1;
    for (int i = size - 2; i >= 0; i--)
        if (s[i] != 'w')
            R[idx(s[i])][i] = R[idx(s[i])][i + 1] + 1;
        else
            R[0][i] = R[0][i + 1] + 1, R[1][i] = R[1][i + 1] + 1;
    for (int i = 0; i < n; i++)
        ans = std::max(ans, std::max(L[0][i], L[1][i]) + std::max(R[0][i], R[1][i]));
    printf("%d", std::min(ans, n));
    return 0;
}