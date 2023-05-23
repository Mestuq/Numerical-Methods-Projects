// Damian Szopiński 185394
//! Uwaga, ten program wymaga C++20, lub nowszy. (na przykład z strony https://winlibs.com/ )

#include <iostream>
#include "func.hpp"

//! Tutaj definiujemy typ, którego będziemy sprawdzać
using type=double;

int main()
{
    std::cout<<"W testach uzyjemy zmiennej long double"<<std::endl;
    
    std::cout<<"-----Ex.1-----\n";
    std::cout.precision(255);
    std::cout<<Zadanie1::checkAcc<type>()<<std::endl;
    std::cout<<"Aby uzyskac e nalezy odjac 1"<<std::endl;
    Zadanie2::funTest<type>();
    std::cout<<"-----Ex.3-----\n";
    std::cout<<"Sposob z ksiazki"<<std::endl;
    for(int x=0;x<10;x++)
        std::cout<<x<<"-sin("<<x<<")="<<Zadanie3::funY<type>(x)<<std::endl;
    std::cout<<"Inny sposob na sinus"<<std::endl;
    for(int x=0;x<10;x++)
        std::cout<<x<<"-sin("<<x<<")="<<Zadanie3::funY2<type>(x)<<std::endl;

    std::cout<<"--------------"<<std::endl
    <<"jesli porownamy sobie 9-sin(9)"<<std::endl
    <<"pierwsza funkcja zwraca 8.58788151475824346 1059306067539864670834504067897796630859375"<<std::endl
    <<"a druga 8.58788151475824345 2385688687655829198774881660938262939453125"<<std::endl
    <<"(spacja oddzielilem moment od ktorego liczby zaczely sie roznic)"<<std::endl
    <<"Na podstawie programow matematycznych obliczylem, ze wynik 8.587881514758243430243727433647564820656123473113027237764394 jest prawidlowy"<<std::endl
    <<"Druga funkcja podala wynik z delikatnie mniejszym bledem, aczkolwiek roznica jest mala"<<std::endl;
    return 0;
}
