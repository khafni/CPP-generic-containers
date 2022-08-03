#pragma once

namespace ft
{

    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2,
                                 Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    /*
    ** using templete specialization we could implement
    ** enable_if that just throw a compile error if a candition is not met
    */
    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    /*
    ** using templete specialization here also we can
    ** make a simple implementation of is_integral
    */
    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T, v> type;
        operator T() { return v; }
    };

    template< class T >
    struct is_integral
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<long long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };
    
    template <class T1, class T2> struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair() : first(), second() {}
        pair(const T1& a, const T2& b) : first(a), second(b) {}
        template <class U1, class U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return *this;
        }   
    };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }
    
}
