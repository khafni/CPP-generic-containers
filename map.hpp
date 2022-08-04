#pragma once
#include <memory>

namespace ft
{
    template<
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, T> >
    > class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type; 
    };
}
