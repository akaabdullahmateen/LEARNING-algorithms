#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>

template <typename Object>
class Vector
{
    std::size_t _size;
    std::size_t _capacity;

public:
    explicit Vector(std::size_t m_size = 0) : _size(m_size), _capacity{m_size + SPARE_CAPACITY}
    {
        _objects = new Object[_capacity];
    }

    ~Vector()
    {
        delete[] _objects;
    }

    Vector(const Vector &rhs) : _size(rhs._size), _capacity(rhs._capacity), _objects{nullptr}
    {
        _objects = new Object[_capacity];
        for (std::size_t idx = 0; idx < _size; ++idx)
            _objects[idx] = rhs._objects[idx];
    }

    Vector(Vector &&rhs) : _size(rhs._size), _capacity(rhs._capacity), _objects(rhs._objects)
    {
        rhs._objects = nullptr;
        rhs._size = 0;
        rhs._capacity = 0;
    }

    Vector &operator=(const Vector &rhs)
    {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    Vector &operator=(Vector &&rhs)
    {
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);
        std::swap(_objects, rhs._objects);
        return *this;
    }

    void resize(std::size_t m_size)
    {
        if (m_size > _capacity)
            std::reserve(m_size * 2);
        _size = m_size;
    }

    void reserve(std::size_t m_capacity)
    {
        if (_capacity < _size)
            return;
        Object *t_objects = new Object[m_capacity];
        for (std::size_t idx = 0; idx < _size; ++idx)
            t_objects[idx] = std::move(_objects[idx]);
        _capacity = m_capacity;
        std::swap(_objects, t_objects);
        delete[] t_objects;
    }
};

#endif