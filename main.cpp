#include <iostream>
#include <utility>
#include <memory>
#include <vector>

// void f(std::auto_ptr<int> p)
// {
//         std::cout << *p << std::endl;
// }
using namespace std;

template <class T>
ostream& operator<<(ostream &strm, const auto_ptr<T> &p)
{
    if (p.get() == NULL)
        strm << NULL;
    else
        strm << *p;
    return strm;
}

int main()
{
    //std::pair<int, int> p(1, 2);
    //std::cout << p.second << std::endl;
    auto_ptr<int> p(new int);
    auto_ptr<int> q;
    *p = 69;

    // f(p);
    // cout << p << endl;
    cout << q;
    // std::cout << std::make_pair(3, 3).second << std::endl;

    return (0);
}