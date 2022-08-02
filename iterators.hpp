#pragma once
#include "iterator_traits.hpp"
#include <algorithm>
namespace ft
{

    template <class Container>
    class random_access_iterator
    {
    public:
        typedef typename iterator_traits<Container *>::value_type value_type;
        typedef typename iterator_traits<Container *>::difference_type difference_type;
        typedef typename iterator_traits<Container *>::iterator_category iterator_category;
        typedef typename iterator_traits<Container *>::pointer pointer;
        typedef typename iterator_traits<Container *>::reference reference;

    protected:
        pointer _ptr;

    public:
        // default constructor
        random_access_iterator() : _ptr(NULL) {}
        // constructor with pointer
        random_access_iterator(pointer ptr) : _ptr(ptr) {}
        
        //copy constructor
        // <template <
        // random_access_iterator(const random_access_iterator<Container> &other) : _ptr(other._ptr) {}
        template <typename ITE>
        random_access_iterator(const random_access_iterator<ITE> &other)
        {
            *this = other.base();
        }
        
        // template <typename ITE>
        // random_access_iterator(const ITE &other)
        // {
        //     _ptr = other->base();
        // }

        
        random_access_iterator &operator=(const random_access_iterator &other)
        {
            _ptr = other._ptr;
            return (*this);
        }

        virtual ~random_access_iterator() {}

        bool operator==(const random_access_iterator &other) const
        {
            return (_ptr == other._ptr);
        }

        bool operator!=(const random_access_iterator &other) const
        {
            return (_ptr != other._ptr);
        }

        reference operator*() const
        {
            return (*_ptr);
        }

        pointer operator->() const
        {
            return (_ptr);
        }

        random_access_iterator operator+(const difference_type &n) const
        {
            random_access_iterator rai = *this;
            rai._ptr += n;
            return (rai);
           // return (_ptr + n);
        }

        random_access_iterator operator+(const random_access_iterator &other) const
        {
            random_access_iterator rai = *this;
            rai._ptr += other._ptr;
            return (rai);
        }

        random_access_iterator operator-(const difference_type &n) const
        {
            random_access_iterator rai = *this;
            rai._ptr -= n;
            return (rai);
        }

        difference_type operator-(const random_access_iterator &other) const
        {
            difference_type diff = this->_ptr - other._ptr;
            // random_access_iterator rai = *this;
            // rai._ptr -= other._ptr;
            return (diff);
        }

        random_access_iterator &operator++()
        {
            _ptr++;
            return (*this);
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator rai = *this;
            ++_ptr;
            return (rai);
        }

        random_access_iterator operator--()
        {
            _ptr--;
            return (*this);
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator rai = *this;
            --_ptr;
            return (rai);
        }

        pointer base() const
        {
            return (_ptr);
        }
        
        bool operator<(const random_access_iterator &other) const
        {
            return (_ptr < other._ptr);
        }

        bool operator<=(const random_access_iterator &other) const
        {
            return (_ptr <= other._ptr);
        }

        bool operator>(const random_access_iterator &other) const
        {
            return (_ptr > other._ptr);
        }

        bool operator>=(const random_access_iterator &other) const
        {
            return (_ptr >= other._ptr);
        }

        random_access_iterator &operator+=(const difference_type n)
        {
            _ptr += n;
            return (*this);
        }

        random_access_iterator &operator-=(const difference_type n)
        {
            _ptr -= n;
            return (*this);
        }

        reference operator[](const difference_type n) const
        {
            return (*(_ptr + n));
        }
    };
    /*
    **  &*(reverse_iterator(i)) == &*(i - 1)
    */
    template <class Iter>
    class reverse_iterator
    {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::reference reference;

    protected:
        iterator_type base_iterator;

    public:
        reverse_iterator() : base_iterator() {}
        template <typename ITE>
        reverse_iterator (const reverse_iterator<ITE> &other) : base_iterator(other.base()) {}
        reverse_iterator(const iterator_type &it) : base_iterator(it) {}
        reverse_iterator(const reverse_iterator &other) : base_iterator(other.base_iterator) {}
        template <typename IT>
        reverse_iterator &operator=(const reverse_iterator<IT> &other)
        {
            base_iterator = other.base();
            return (*this);
        }

        // reverse_iterator &operator=(const iterator_type &it)
        // {
        //     base_iterator = it;
        //     return (*this);
        // }

        virtual ~reverse_iterator() {}

        iterator_type base() const
        {
            return (base_iterator);
        }
        // For a reverse iterator r constructed
        // from an iterator i, the relationship
        //  &*r == &*(i-1) is always true
        //(as long as r is dereferenceable);
        reference operator*() const
        { 
            return *(iterator_type(base_iterator - 1));
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        reference operator[](const difference_type n) const
        {
            return base_iterator[-n - 1];
        }

        reverse_iterator &operator++()
        {
            base_iterator--;
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator ri = *this;
            ++ri.base_iterator;
            return (ri);
        }

        reverse_iterator &operator--()
        {
            base_iterator++;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator ri = *this;
            --ri.base_iterator;
            return (ri);
        }

        reverse_iterator operator+(const difference_type n) const
        {
            return (reverse_iterator(base_iterator - n));
        }

        reverse_iterator operator-(const difference_type n) const
        {
            return (reverse_iterator(base_iterator + n));
        }

     

        reverse_iterator &operator+=(const difference_type n)
        {
            // std::cout << "zbi" << std::endl;
            this->base_iterator -= n;
            // this->base() -= n;
            return (*this);
        }

        reverse_iterator &operator-=(const difference_type n)
        {
            this->base_iterator += n;
            return (*this);
        }
    };

    template <class Iterator>
    bool operator==(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() == y.base());
        }

    template <class Iterator>
    bool operator!=(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() != y.base());
        }
    
    template <class Iterator>
    bool operator<(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() > y.base());
        }
    
    template <class Iterator>
    bool operator>(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() < y.base());
        }
    
    template <class Iterator>
    bool operator<=(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() >= y.base());
        }
    
    template <class Iterator>
    bool operator>=(
        const reverse_iterator<Iterator> &x,
        const reverse_iterator<Iterator> &y)
        {
            return (x.base() <= y.base());
        }
    template <class container>
    random_access_iterator<container> operator+(int n, const random_access_iterator<container> &it)
    {
        random_access_iterator<container> rai(it + n);
        return (rai);
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
    {
        reverse_iterator<Iterator> rai(it);
        rai += n;
        return (rai);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(reverse_iterator<Iterator> &it1, reverse_iterator<Iterator> &it2)
    {
        return it2.base().base() - it1.base().base();
    }
}