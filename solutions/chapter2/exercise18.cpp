#include <iostream>

double function(double x)
{
    return x * x * x + 2 * x - 5;
}

double findRoot(double (*f)(double), double low, double high)
{
    double epsilon = 0.001;
    double mid;
    double f_mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        f_mid = f(mid);
        if(f_mid < -1 * epsilon)
            low = mid;
        else if(f_mid > epsilon)
            high = mid;
        else{
            return mid;
        }
    }
    return 404;
}

int main()
{
    std::cout << findRoot(function, 1, 1.5) << std::endl;
    return 0;
}