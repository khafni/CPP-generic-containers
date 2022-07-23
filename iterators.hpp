#pragma once
# include "iterator_traits.hpp"
# include <algorithm>
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

        random_access_iterator operator+(const difference_type n) const
        {
            random_access_iterator rai = *this;
            rai._ptr += n;
            return (rai);
        }

        // random_access_iterator operator+(const random_access_iterator &other) const
        // {
        //     random_access_iterator rai = *this;
        //     rai._ptr += other._ptr;
        //     return (rai);
        // }

        

        random_access_iterator operator-(const difference_type n) const
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
            rai._ptr++;
            return (rai);
        }

        random_access_iterator operator--() const
        {
            random_access_iterator rai = *this;
            rai._ptr -= 1;
            return (rai);
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
        reverse_iterator(const iterator_type &it) : base_iterator(it) {}
        reverse_iterator(const reverse_iterator &other) : base_iterator(other.base_iterator) {}
        reverse_iterator &operator=(const reverse_iterator &other)
        {
            base_iterator = other.base_iterator;
            return (*this);
        }
        virtual ~reverse_iterator() {}

        iterator_type base()
        {
            return base_iterator;
        }
        // For a reverse iterator r constructed
        // from an iterator i, the relationship
        //  &*r == &*(i-1) is always true
        //(as long as r is dereferenceable);
        reference operator*() const
        {
            return *(base()--);
        }

        pointer operator->() const
        {
            return (base() - 1);
        }

        reference operator[](const difference_type n) const {
            return *(base() + n - 1);
        }

        reverse_iterator operator++() const
        {
            reverse_iterator ri = *this;
            ri.base()++;
            return (ri);
        }

        reverse_iterator operator--() const
        {
            reverse_iterator ri = *this;
            ri.base()--;
            return (ri);
        }

        reverse_iterator operator+(const difference_type n) const
        {
            reverse_iterator ri = *this;
            ri.base() += n;
            return (ri);
        }

        // reverse_iterator operator+(random_access_iterator other) const
        // {
        //     reverse_iterator ri = *this;
        //     ri.base() += n;
        //     return (ri);
        // }



        reverse_iterator operator-(const difference_type n) const
        {
            reverse_iterator ri = *this;
            ri.base() -= n;
            return (ri);
        }
 
        
        
        reverse_iterator &operator+=(const difference_type n)
        {
            this->base() += n;
            return (*this);
        }

        reverse_iterator &operator-=(const difference_type n)
        {
            this->base() -= n;
            return (*this);
        }

    };
}