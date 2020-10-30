#include <iostream>
#include <exception>

int fib(int n)
{
    // compute the nth Fibonacci number
    int firstPointer = 0,
        secondPointer = 1;
        
    if (n < 0) throw std::invalid_argument("Cannot find a number less than zero");
    else if (n <= 1) return n;
    
    int index = 1,
        fibo{0};
    
    while (index < n)  {
        fibo = firstPointer + secondPointer;
        ++index;
        firstPointer = secondPointer;
        secondPointer = fibo;
    }

    return fibo;
}