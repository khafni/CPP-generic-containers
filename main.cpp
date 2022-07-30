#include <iostream>
#include <utility>
#include <memory>
#include <vector>
#include <cstdio>
#include "iterators.hpp"
#include "vector.hpp"

void print_elem (int elem)
{
    std::cout << elem << std::endl;
}
int main()
{
    // std::cout << "wesh" << std::endl;
    // std::vector<int>::iterator it;
    // int *ptr = new int(5);
    // int *ptr(NULL);
    std::vector<int> v1;
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(7);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    // std::cout << *(v.erase(std::find(v.begin(), v.end(), 2))) << std::endl;
    // v.erase(std::find(v.begin(), v.end(), 2));
    // std::vector<int>::iterator it1 = std::find(v.begin(), v.end(), 1);
    // std::vector<int>::iterator it2 = std::find(v.begin(), v.end(), 3);
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 1);
    std::cout << it[0] << std::endl;
    std::cout << std::vector<int>::reverse_iterator(it)[-2] << std::endl;
    int i = 0;
    std::cout << i++ << std::endl;
    // v.erase(it1, it2);
    // std::cout << *(v.erase(it1, it2)) << std::endl;
    // v.insert(std::find(v.begin(), v.end(), 4), v1.begin(), v1.end());
    // for (int i = 0, j = 0; i < 0 && j < 0; i++,j++)
    // {
    //     std::cout << "i: " << i << "j: " << std::endl;
    // }
    // std::cout << v.size() << std::endl;
    // ft::vector<int>::iterator it = v.begin();
    // it++;
    // ft::vector<int>::iterator it1 = it + 3;
    // it++; 
    // std::vector<int>::reverse_iterator rit(it);
    // std::cout << (it1 - it) << std::endl;
    // std::cout << *rit << std::endl;
    // std::cout << *(it++) << std::endl;
    // for (size_t i = 0; i < v.size(); i++)
        // std::cout << v[i] << std::endl;
        
    // int i(0);

    // std::vector<int>::reverse_iterator ri(v.begin());
    // std::cout << (ri[0]) << std::endl;

    // std::for_each(v.begin(), v.end(), print_elem);
    // std::for_each(v1.begin(), v1.end(), print_elem);
    // ptr();
    // printf("%p\n", ptr);
    return (0);
}