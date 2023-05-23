// metodnumeryczne.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>

using namespace std;

float x(float x0, int i, float h) {
    float x = x0 + i * h;
    return x;
}
float f(float x) {
    float wynik;
    wynik =  2 * pow(x,2) - 4 * x + 12;
    return wynik;
}
float g(float x) {
    float wynik;
    wynik = sin(x);
    return wynik;
}
float m(float x) {
    float wynik;
    wynik = sin(x) + 3*pow(x, 2) + 14 * x - 1;
    return wynik;
}

int main()
{
    //metoda trapezow
    float wynikK=0, wynikG = 0, wynikM = 0, suma = 0,x0 = 1, xn = 10, xi = x0;
    float h;
    int n;
    //(b-a)/n=h //b=xn, a=x0
    cout << "wyniki dla funkcji f(x)=2 * pow(x,2) - 4 * x + 12\n";
    cout << "dla n od 1 do 14\n";
    for (n = 1; n < 15;++n) {
        h = (xn - x0) / n;
            for(int i = 0; i < n; ++i) {
                suma = f(x(x0,i,h))+f(x(x0,(i+1),h));
                wynikK += (h / 2) * (suma); 
            }
        cout << wynikK << endl;
        wynikK = 0;
    }
    cout << "wyniki dla funkcji f(x)=2 * pow(x,2) - 4 * x + 12\n";
    cout << "dla n 99999\n";
    h = (xn - x0) / 99999;
    for (int i = 0; i < n; ++i) {
        suma = f(x(x0, i, h)) + f(x(x0, (i + 1), h));
        wynikK += (h / 2) * (suma);
    }
    cout << wynikK << endl;
    

    cout << "\n funkcja g(x)=sin(x)\n";
    cout << "dla n od 1 do 14\n";
    for (n = 1; n < 15; ++n) {
        x0 = 1; xn = 100;
        xi = x0;
        h = (xn - x0) / n;

        for (int i = 0; i < n; ++i) {
            suma = g(x(x0, i, h)) + g(x(x0, (i + 1), h));
            wynikG += (h / 2) * (suma);
        }
        cout << wynikG << endl;
        wynikG = 0;
    }
    cout << "dla n 99999\n";
    x0 = 1; xn = 100;
    xi = x0;
    h = (xn - x0) / 99999;

    for (int i = 0; i < n; ++i) {
        suma = g(x(x0, i, h)) + g(x(x0, (i + 1), h));
        wynikG += (h / 2) * (suma);
    }
    cout << wynikG << endl;

    
    cout << "\n funkcja m(x)=sin(x) + 3*pow(x, 2) + 14 * x - 1\n";
    cout << "dla n od 1 do 14\n";
    for (n = 1; n < 15; ++n) {
        x0 = 1; xn = 50;
        xi = x0;
        h = (xn - x0) / n;

        for (int i = 0; i < n; ++i) {
            suma = m(x(x0, i, h)) + m(x(x0, (i + 1), h));
            wynikM += (h / 2) * (suma);
        }

        cout << wynikM << endl;
        wynikM = 0;

    }
    cout << "dla n 99999\n";
    x0 = 1; xn = 100;
    xi = x0;
    h = (xn - x0) / 99999;

    for (int i = 0; i < n; ++i) {
        suma = m(x(x0, i, h)) + m(x(x0, (i + 1), h));
        wynikM += (h / 2) * (suma);
    }       
    
    cout << wynikM << endl;
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
