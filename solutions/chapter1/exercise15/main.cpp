#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "rectangle.h"
#include "area_compare.h"
#include "perimeter_compare.h"
#include "header.h"

#define MAX 10

std::size_t getRandom()
{
    return rand() % 100;
}

void print(const std::vector<Rectangle> &rectangles)
{
    for(const Rectangle &rect : rectangles)
    {
        std::cout << "[NAME] \t\t: " << rect.getName() << std::endl;
        std::cout << "[LENGTH] \t: " << rect.getLength() << std::endl;
        std::cout << "[WIDTH] \t: " << rect.getWidth() << std::endl;
        std::cout << "[AREA] \t\t: " << rect.getArea() << std::endl;
        std::cout << "[PERIMETER] \t: " << rect.getPerimeter() << std::endl;
        std::cout << std::endl;
    }
}

void populate(std::vector<Rectangle> &rectangles)
{
    std::string name;
    for(std::vector<Rectangle>::size_type idx = 0; idx < MAX; ++idx)
    {
        name = "Rectangle #" + std::to_string(idx + 1);
        rectangles.push_back(Rectangle(getRandom(), getRandom(), name));
    }
}

void seed()
{
    std::srand(std::time(NULL));
}

void compare(const std::vector<Rectangle> &rectangles)
{
    std::cout << "[AREA COMPARE] \t\t: " << findMax(rectangles, AreaCompare{}) << std::endl;
    std::cout << "[PERIMETER COMPARE] \t: " << findMax(rectangles, PerimeterCompare{}) << std::endl;
}

int main()
{
    std::vector<Rectangle> rectangles;
    seed();
    populate(rectangles);
    print(rectangles);
    compare(rectangles);
    return 0;
}