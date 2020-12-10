#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <map>
#include <iostream>

// int len;
double ans;
std::string str;
std::map<std::string, double> M;

void prepare()
{
    M["H"] = 1, M["C"] = 12, M["N"] = 14, M["O"] = 16, M["F"] = 19, M["Na"] = 23, M["Mg"] = 24, M["Al"] = 27, M["Si"] = 28;
    M["P"] = 31, M["S"] = 32, M["Cl"] = 35.5, M["K"] = 39, M["Ca"] = 40, M["Mn"] = 55, M["Fe"] = 56, M["Cu"] = 64, M["Zn"] = 65;
    M["Ag"] = 108, M["I"] = 127, M["Ba"] = 137, M["Hf"] = 178.5, M["Pt"] = 195, M["Au"] = 197, M["Hg"] = 201;
    std::cin >> str;
}

double solve(int p)
{
    double sum = 0, res = 0;
    while (str[p] != ')')
    {
        if (isupper(str[p]))
        {
            sum += res;
            res = 0;
            // std::cout << p << " " << str.substr(p, 2) << std::endl;
            if (islower(str[p + 1]))
                res = M[str.substr(p, 2)], p += 2;
            else
                res = M[str.substr(p, 1)], p++;
        }
        else if (str[p] == '(')
        {
            sum += res;
            res = 0;
            int pos = p + 1;
            for (int layer = 1; layer; pos++)
                if (str[pos] == '(')
                    layer++;
                else if (str[pos] == ')')
                    layer--;
            res = solve(p + 1);
            p = pos;
        }
        else if (str[p] == '_')
        {
            p += 2;
            int cnt = 0;
            while (isdigit(str[p]))
                cnt = cnt * 10 + str[p++] - 48;
            res *= cnt;
            p++;
        }
    }
    return sum + res;
}

int main()
{
    prepare();
    int pos = str.find('~');
    if (pos != -1)
    {
        for (int tmp = pos + 1; isdigit(str[tmp]); tmp++)
            ans = ans * 10 + str[tmp] - '0';
        str.erase(pos, 100);
        ans = 18 * (ans + (ans == 0));
    }
    str += ')';
    std::cout << ans + solve(0);
    // << len << '\n';
    // int L = str.find('(');
    // int R = str.find(')');
    // if (L != -1 and R != -1)
    // {
    //     double x = 0, y = 0;
    //     x += add_ele(L + 1, R);
    // }
    // std::cout << str << '\n'
    //           << res << '\n'
    //           << len << '\n';
    return 0;
}