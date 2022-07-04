#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle
{
public:
    explicit Rectangle(const std::size_t m_length = 0, const std::size_t m_width = 0, const std::string m_name = std::string{})
    : length{m_length}, width{m_width}, name{m_name} {};
    
    std::size_t getLength() const
    {
        return length;
    }

    std::size_t getWidth() const
    {
        return width;
    }
    
    std::string getName() const
    {
        return name;
    }

    std::size_t getArea() const
    {
        return length * width;
    }

    std::size_t getPerimeter() const
    {
        return 2 * (length + width);
    }

private:
    std::size_t length;
    std::size_t width;
    std::string name;
};

#endif