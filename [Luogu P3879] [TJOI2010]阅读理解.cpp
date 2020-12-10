#include <iostream>
#include <map>
#include <set>
#include <string>

std::map< std::string, std::set<int> > map;
std::set<int>::iterator iter;

int main()
{
    int n, m;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int len;
        std::cin >> len;
        for (int j = 0; j < len; ++j)
        {
            std::string str;
            std::cin >> str;
            map[str].insert(i);
        }
    }
    std::cin >> m;
    while (m--)
    {
        std::string str;
        std::cin >> str;
        if (map.count(str))
            for (iter = map[str].begin(); iter != map[str].end(); ++iter)
                std::cout << *iter << " ";
        std::cout << std::endl;
    }
    return 0;
}