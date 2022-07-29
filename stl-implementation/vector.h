#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>

namespace ctl
{
    template<typename T>
    class vector
    {
    public:
        typedef T                                       value_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef value_type*                             iterator;
        typedef const value_type*                       const_iterator;
        typedef std::reverse_iterator<iterator>         reverse_iterator;
        typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
        typedef std::ptrdiff_t                          difference_type;
        typedef std::size_t                             size_type;

        explicit vector();
        explicit vector(size_type n);
        explicit vector(size_type n, const value_type& val);

        vector(const vector& x);
        vector(vector&& x);
        vector(std::initializer_list<value_type> il);
        
        ~vector();

        vector& operator=(const vector& x);
        vector& operator=(vector&& x);
        vector& operator=(std::initializer_list<value_type> il);

        iterator begin() noexcept;
        const_iterator begin() const noexcept;

        iterator end() noexcept;
        const_iterator end() const noexcept;

        reverse_iterator rbegin() noexcept;
        const_reverse_iterator rbegin() const noexcept;

        reverse_iterator rend() noexcept;
        const_reverse_iterator rend() const noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

        size_type size() const noexcept;
        size_type max_size() const noexcept;
        size_type capacity() const noexcept;

        void resize(size_type n);
        void resize(size_type n, const value_type& val);

        void reserve(size_type n);
        void shrink_to_fit();

        bool empty() const noexcept;

        reference operator[](size_type n);
        const_reference operator[](size_type n) const;

        reference at(size_type n);
        const_reference at(size_type n) const;

        reference front();
        const_reference front() const;

        reference back();
        const_reference back() const;

        value_type* data();
        const value_type* data() const;

        void assign(size_type n, const value_type& val);
        void assign(std::initializer_list<value_type> il);

        void push_back(const value_type& val);
        void push_back(value_type&& val);

        void pop_back();

        iterator insert(const_iterator position, const value_type& val);
        iterator insert(const_iterator position, size_type n, const value_type& val);
        iterator insert(const_iterator position, value_type&& val);
        iterator insert(const_iterator position, initializer_list<value_type> il);

        iterator erase(const_iterator position);
        iterator erase(const_iterator first, const_iterator last);

        void swap(vector& x);

        void clear() noexcept;

        iterator emplace(const_iterator position, const value_type& val);
        iterator emplace(const_iterator position, value_type&& val);

        bool operator==(const vector& rhs);
        bool operator!=(const vector& rhs);
        bool operator<(const vector& rhs);
        bool operator<=(const vector& rhs);
        bool operator>(const vector& rhs);
        bool operator>=(const vector& rhs);
    };
}

#endif