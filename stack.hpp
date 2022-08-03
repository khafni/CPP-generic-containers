#pragma once
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef typename container_type::size_type size_type;
            typedef typename container_type::reference	reference;
        protected:
            Container _container;
        public:
        explicit stack (const container_type& ctnr = container_type())
        {
            _container = ctnr;
        }
        ~stack() {}
        stack& operator=( const stack& other )
        {
            _container = other._container;
            return *this;
        }

        /*
        ** Element access
        */

        reference top()
        {
            return _container.back();
        }

        const value_type& top() const
        {
            return _container.back();
        }
        
        /*
        **  Capacity
        */

        bool empty() const
        {
            return _container.empty();
        }

        size_type size() const
        {
            return _container.size();
        }

        /*
        **Modifiers
        */

        void push (const value_type& val)
        {
            _container.push_back(val);
        }

        void pop()
        {
            _container.pop_back();
        }

    template <class T_, class Container_>
    friend bool operator==(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   

    template <class T_, class Container_>
    friend bool operator!=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   

    template <class T_, class Container_>
    friend bool operator<(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   

    template <class T_, class Container_>
    friend bool operator>(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   

    template <class T_, class Container_>
    friend bool operator<=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   

    template <class T_, class Container_>
    friend bool operator>=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
   
    };

    /*
    ** Non-member functions
    */
    template <class T_, class Container_>
    bool operator==(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container == rhs._container);
    }

    template <class T_, class Container_>
    bool operator!=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container != rhs._container);
    }

    template <class T_, class Container_>
    bool operator<(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container < rhs._container);
    }

    template <class T_, class Container_>
    bool operator>(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container > rhs._container);
    }

    template <class T_, class Container_>
    bool operator<=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container <= rhs._container);
    }

    template <class T_, class Container_>
    bool operator>=(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs)
    {
        return (lhs._container >= rhs._container);
    }
    


}