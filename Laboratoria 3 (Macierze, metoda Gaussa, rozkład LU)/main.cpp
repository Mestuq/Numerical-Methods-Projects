#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "gauss.h"
#include "LU.h"

int main()
{
    std::cout<<"Eliminacja Gaussa:\n";
    std::cout<<"Przypadki w ktorych eliminacja zawodzi:\n";


    std::cout<<"Macierz 1:\n";
    for (float a:GaussElimination("matrix1.txt",false))
        std::cout<<a<<'\t';


    std::cout<<"\n\n\n";
    std::cout<<"Macierz 2:\n";
    for (float a:GaussElimination("matrix2.txt",false))
        std::cout<<a<<'\t';


    std::cout<<"\n\n\n";
    std::cout<<"Przyklad poprawny:\n";
    for (float a:GaussElimination("przyklad.txt",true))
        std::cout<<a<<'\t';

    std::cout<<"\n\n\n";
    std::cout<<"Przyklad z wykladu:\n";
    for (float a:GaussElimination("wyklad.txt",true))
        std::cout<<a<<'\t';

    std::cout<<"\n\n\n";
    std::cout<<"Wszystkie mozliwe przestawienia wierszy (macierz pw 3x3)\n";
    for (float a:GaussElimination("pw1.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";
    for (float a:GaussElimination("pw2.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";
    for (float a:GaussElimination("pw3.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";
    for (float a:GaussElimination("pw4.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";
    for (float a:GaussElimination("pw5.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";
    for (float a:GaussElimination("pw6.txt",true))
        std::cout<<a<<'\t';
        std::cout<<"\n";


    std::cout<<"\n\n\n";
    std::cout<<"Metoda LU:\n";

    metodaLU();
    return 0;
}
