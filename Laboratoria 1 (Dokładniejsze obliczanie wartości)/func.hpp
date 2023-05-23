#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>
#include <concepts>

//Sprawdzamy czy sprawdzana zmienna spełnia warunki bycia liczbą
template <typename T>
concept NumericType =
(requires(std::ostream& os, T a)//Drukowanie w oknie CMD
{
    os << a;
})
&&
(requires(T a,T b)//Proste operacje
{
    a<b;
    a>b;
    a=b;
    a-b;
    a+b;
    a*b;
    a/b;
}
);

//! Inne biblioteki zawierające funkcje matematyczne mogłyby się tu okazać wąskim gardłem, gdyż często korzystają z double, dlatego napisałem swoje.
namespace Math
{
    //! Potęgowanie k do stopnia v
    template<NumericType num> num Pow(num k,num v);
    //! Pierwiastkowanie k (pierwiastek drugiego stopnia)
    template<NumericType num> num Sqrt(num k,int precision=100,num from=0,num to=0);
    //! Sinus liczby Wzór z książki
    template<NumericType num> num Sin(num x, int precision=100);
    //! Inny wzór na liczenie sinusa jaki znalazłem
    template<NumericType num> num Sin2(num x, int precision=100);
    //! Silnia
    template<NumericType num> num Factorial(num x);
}

namespace Zadanie1
{
    template<NumericType num> num checkAcc();
}

namespace Zadanie2
{
    template<NumericType num> num funF(num x);
    template<NumericType num> num funG(num x);
    template<NumericType num> void funTest();
}

namespace Zadanie3
{
    //! Liczenie z sinusa z książki
    template<NumericType num> num funY(num x);
    //! Liczenie sinusa innym sposobem
    template<NumericType num> num funY2(num x);
}

#include "func.tpp"
#endif // FUNC_HPP