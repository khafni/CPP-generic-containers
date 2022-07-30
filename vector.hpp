#pragma once
#include <memory>
#include "iterators.hpp"
namespace ft
{
    template <
        class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef random_access_iterator<value_type> iterator;
        typedef random_access_iterator<const value_type> const_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef typename allocator_type::size_type size_type;

    private:
        allocator_type _alloc;
        pointer _data;
        size_type _len;
        size_type _alloc_size;

    public:
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(NULL), _len(0), _alloc_size(0) {}

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) : _alloc(alloc), _len(n), _alloc_size(n)
        {
            this->_data = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(&_data[i], val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type()) : _alloc(alloc)
        {
            size_type d = std::distance(first, last);
            _data = _alloc.allocate(d);
            _len = d;
            _alloc_size = d;
            for (size_type i = 0; i < d; i++)
                _data + i = _alloc.construct((_data + i), *(first + i));
        }

        vector(const vector &x)
        {
            _alloc = x._alloc;
            this->_alloc_size = x._alloc_size;
            this->_len = x._len;
            this->_data = _alloc.allocate(x._alloc_size);
            for (size_type i = 0; i < _len; i++)
                this->_data + i = _alloc.construct((x._data + i), *(x._data + i));
        }

        ~vector()
        {
            if (_alloc_size > 0)
                _alloc.deallocate(_data, _alloc_size);
        }

        vector &operator=(const vector &x)
        {
            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            if (this->_alloc_size < x._alloc_size)
                _alloc.deallocate(_data, _alloc_size);
            _alloc = x._alloc;
            this->_alloc_size = x._alloc_size;
            this->_len = x._len;
            this->_data = _alloc.allocate(x._alloc_size);
            for (size_type i = 0; i < _len; i++)
                this->_data + i = _alloc.construct((x._data + i), *(x._data + i));
            return (*this);
        }

        iterator begin()
        {
            return iterator(this->_data);
        }

        const_iterator begin() const
        {
            return const_iterator(this->_data);
        }

        iterator end()
        {
            if (!_len)
                return iterator(this->_data);
            return iterator(this->_data + _len);
        }

        const_iterator end() const
        {
            if (!_len)
                return const_iterator(this->_data);
            return const_iterator(this->_data + _len);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        // Capacity

        bool empty() const
        {
            if (!_len)
                return true;
            return false;
        }

        size_type size() const
        {
            return (this->_len);
        }

        void reserve(size_type n)
        {
            if (n < this->capacity())
                return;
            pointer tmp = _alloc.allocate(n);
            for (size_type i = 0; i < _len; i++)
                _alloc.construct((tmp + i), *(this->_data + i));
            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, _alloc_size);
            _data = tmp;
            _alloc_size = n;
        }

        size_type capacity() const
        {
            return (this->_alloc_size);
        }

        // Element access
        reference at(size_type n)
        {
            if (n > _len)
                throw(std::out_of_range("vector out of range access exception"));
            return *(_data + n);
        }

        const_reference at(size_type n) const
        {
            if (n > _len)
                throw(std::out_of_range("vector out of range access exception"));
            return *(_data + n);
        }

        reference operator[](size_type pos)
        {
            return *(_data + pos);
        }

        const_reference operator[](size_type pos) const
        {
            return *(_data + pos);
        }

        reference front()
        {
            return *(_data);
        }

        const_reference front() const
        {
            return *(_data);
        }

        reference back()
        {
            return *(_data + _len - 1);
        }

        const_reference back() const
        {
            return *(_data + _len - 1);
        }

        // Modifiers
        void clear()
        {
            for (int i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            _len = 0;
        }

        void push_back(const value_type &val)
        {
            size_type new_allc = 1 + (2 * _len);
            if (_len >= _alloc_size)
            {
                reserve(new_allc);
            }
            *(_data + _len) = val;
            _len++;
        }
        void pop_back()
        {
            if (_len)
            {
                _alloc.destroy(_data + _len - 1);
                _len--;
            }
        }

        iterator insert(iterator position, const value_type &val)
        {
            size_type new_allc = 1 + (2 * _len);
            pointer _data_tmp;
            if (_len >= _alloc_size)
            {
                _data_tmp = _alloc.allocate(new_allc);
                _alloc_size = new_allc;
            }
            else
                _data_tmp = _alloc.allocate(_alloc_size);
            // std::uninitialized_copy is like std::copy but
            //  it constructs the objects it copies with thier
            //  proper default constructor.
            std::uninitialized_copy(this->begin(), position, iterator(_data_tmp));
            _alloc.construct(_data_tmp + (position - this->begin()), val);
            std::uninitialized_copy(position, this->end(), iterator(_data_tmp) + (position - this->begin()) + 1);
            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, _alloc_size);
            _len++;
            this->_data = _data_tmp;
            return iterator(_data_tmp) + (position - this->begin());
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            difference_type pos_indx = position - begin();
            difference_type inpt_size = last - first;
            size_type new_allc = 1 + (2 * (_len + inpt_size));
            pointer _data_tmp;
            if (_len + inpt_size >= _alloc_size)
            {
                _data_tmp = _alloc.allocate(new_allc);
                _alloc_size = new_allc;
            }
            else
                _data_tmp = _alloc.allocate(_alloc_size);
            std::uninitialized_copy(this->begin(), position, iterator(_data_tmp));
            // // std::uninitialized_copy(first, last, iterator(_data_tmp + pos_indx));
            for (size_type i = 0; i < inpt_size; i++)
                _alloc.construct(_data_tmp + pos_indx + i, *(first + i));
            std::uninitialized_copy(position, this->end(), iterator(_data_tmp) + pos_indx + inpt_size);
            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, _alloc_size);
            _len += inpt_size;
            this->_data = _data_tmp;
            std::cerr << "zbi" << std::endl;
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            if (!n)
                return;
            size_type new_allc = 1 + (2 * (_len + n));
            difference_type pos_indx = position - begin();
            pointer _data_tmp;
            if (_len + n >= _alloc_size)
            {
                _data_tmp = _alloc.allocate(new_allc);
                _alloc_size = new_allc;
            }
            else
                _data_tmp = _alloc.allocate(_alloc_size);
            // std::uninitialized_copy is like std::copy but
            //  it constructs the objects it copies with thier
            //  proper default constructor.
            std::uninitialized_copy(this->begin(), position, iterator(_data_tmp));
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_data_tmp + pos_indx + i, val);
            std::uninitialized_copy(position, this->end(), iterator(_data_tmp) + pos_indx + n);
            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, _alloc_size);
            _len += n;
            this->_data = _data_tmp;
        }

        iterator erase(iterator position)
        {
            pointer tmp = _alloc.allocate(_alloc_size);
            difference_type pos_indx = position - begin();
            for (size_type i = 0; i < pos_indx; i++)
            {
                _alloc.construct(tmp + i, *(_data + i));
                _alloc.destroy(_data + i);
            }
            _alloc.destroy(_data + pos_indx);
            for (size_type i = pos_indx + 1; i < _len; i++)
            {
                _alloc.construct(tmp + i - 1, *(_data + i));
                _alloc.destroy(_data + i);
            }
            _data = tmp;
            _len--;
            return (iterator(_data + pos_indx));
        }

        iterator erase(iterator first, iterator last)
        {
            pointer tmp = _alloc.allocate(_alloc_size);
            difference_type first_indx = first - begin();
            difference_type last_indx = last - begin();
            for (size_type i = 0; i < first_indx; i++)
            {
                _alloc.construct(tmp + i, *(_data + i));
                _alloc.destroy(_data + i);
            }
            for (size_type i = first_indx; i < last_indx; i++)
                _alloc.destroy(_data + i);
            for (size_type i = last_indx, j = first_indx; i < _len; i++, j++)
            {
                _alloc.construct(tmp + (j), *(_data + i));
                _alloc.destroy(_data + i);
            }
            _data = tmp;
            _len -= (last - first);
            return (iterator(_data + (last - begin())));
        }

        void swap(vector &other)
        {
            std::swap(_data, other._data);
            std::swap(_len, other._len);
            std::swap(_alloc_size, other._alloc_size);
        }
    };

    template <class T, class Alloc>
    bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        if (lhs.size() < rhs.size())
            return true;
        else if (lhs.size() > rhs.size())
            return false;
        else
        {
            for (size_t i = 0; i < lhs.size(); ++i)
            {
                if (lhs[i] < rhs[i])
                    return true;
                else if (lhs[i] > rhs[i])
                    return false;
            }
            return false;
        }
    }

    template <class T, class Alloc>
    bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs > rhs);
    }

    template <class T, class Alloc>
    bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
    {
        lhs.swap(rhs);
    }
}