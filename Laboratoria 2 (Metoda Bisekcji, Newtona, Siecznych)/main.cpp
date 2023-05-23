//Maciej Pestka
//Damian Szopiński 185394

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int M=9;//Liczba probek
double sigma=0.0000000000000002220446049250313080847263336181640625;//mala liczba
double epsilon=sigma;

double f(double x){
    return pow(x,3)+2*(pow(x,2))+x-2;
}
double ff(double x){ //pochodnia funkcji f
   return 3*pow(x,2)+4*x+1;
}
double g(double x){
    return (x*x)-x;
}
double k(double x){
    return sin(x);
}
double sgn(double x)
{
    if(x==0)
        return 0;
    if(x>0)
        return 1;
    return -1;
}

double bisekcjaF()
{ //dla funkcji f(x)
    double w,c;
    double a=0.6;
    double b=0.7;
    double u=f(a);
    double v=f(b);
    double e=b-a;
    if(sgn(u)==sgn(v)){
        cout<<"Znak taki sam!\n";
        return c;
    }
    fstream BisekcjaF("BisekcjaF.txt",ios::out);
    for(int k=1;k<M+1;++k)
    {
        e=e/2;
        c=a+e;
        w=f(c);
        if (abs(e)<sigma || abs(w)<epsilon){
            cout<<"Przerwano w M="<<k<<"\n";
            break;
            //return c;
        }
        if(signbit(w)!=signbit(v)){
            b=c;
            v=w;
        }else{
            a=c;
            u=w;
        }
        cout<<c<<'\n';
        BisekcjaF<<fixed<<setprecision(64)<<c<<'\n';
    }
    cout<<c<<'\n';
    BisekcjaF.close();
    return c;
}
double bisekcjaG()
{ //dla funkcji g(x)
    double w,c;
    double a=0.9;
    double b=1.1;
    double u=g(a);
    double v=g(b);
    double e=b-a;
    if(sgn(u)==sgn(v))
    {
        cout<<"Znak taki sam!\n";
        return c;
    }
    fstream BisekcjaG("BisekcjaG.txt",ios::out);
    for(int k=1;k<M+1;++k)
    {
        e=e/2;
        c=a+e;
        w=g(c);
        if (abs(e)<sigma || abs(w)<epsilon){
            cout<<"Przerwano w M="<<k<<"\n";
            //break;// nie moge tego przerwac bo wykres bylby urwany
        }
        if(signbit(w)!=signbit(v)){
            b=c;
            v=w;
        }else{
            a=c;
            u=w;
        }
        cout<<c<<'\n';
        BisekcjaG<<fixed<<setprecision(64)<<c<<'\n';
    }
    BisekcjaG.close();
    return c;
}
double bisekcjaK()
{ //dla funkcji k(x)
    double w,c;
    double a=3.1;
    double b=3.2;
    double u=k(a);
    double v=k(b);
    double e=b-a;
    if(sgn(u)==sgn(v))
    {
        cout<<"Znak taki sam!\n";
        return c;
    }
    fstream BisekcjaK("BisekcjaK.txt",ios::out);
    for(int k1=1;k1<M+1;++k1){
        e=e/2;
        c=a+e;
        w=k(c);
        if (abs(e)<sigma || abs(w)<epsilon){
            cout<<"Przerwano w M="<<k<<"\n";
            break;
            //return c;
        }
        if(signbit(w)!=signbit(v)){
            b=c;
            v=w;
        }else{
            a=c;
            u=w;
        }
        cout<<c<<'\n';
        BisekcjaK<<fixed<<setprecision(64)<<c<<'\n';
    }
    BisekcjaK.close();
    return c;
}
int main()
{
    //double f = x^3+2x^2+x-2
    //double g = pow(x,2)-x;
    //double k = sin(x)

    cout<<"METODA NEWTONA:\n";
    {
        double x0=0.7;
        double xn=f(x0);
        cout<<"f(x)\n"<<xn<<'\n';
        fstream MetodaNewtonaF("MetodaNewtonaF.txt",ios::out);
        for(int i=0;i<M;++i)
        {
            xn=xn-(f(xn)/ff(xn));
            cout<<xn<<'\n';
            MetodaNewtonaF<<fixed<<setprecision(64)<<xn<<'\n';
        }
        MetodaNewtonaF.close();
    }
    
    {
        double x0=1.4;
        double xn=g(x0);
        cout<<"g(x)\n"<<xn<<'\n';
        fstream MetodaNewtonaG("MetodaNewtonaG.txt",ios::out);
        for(int i=0;i<M;++i)
        {
            xn=xn-(g(xn)/(2*xn-1));
            cout<<xn<<'\n';
            MetodaNewtonaG<<fixed<<setprecision(64)<<xn<<'\n';
        }
        MetodaNewtonaG.close();
    }
    {
        double x0=4;
        double xn=k(x0);
        cout<<"k(x)\n"<<xn<<'\n';
        fstream MetodaNewtonaK("MetodaNewtonaK.txt",ios::out);
        for(int i=0;i<M;++i)
        {
            xn=xn-(k(xn)/(2*xn-1));
            cout<<xn<<'\n';
            MetodaNewtonaK<<fixed<<setprecision(64)<<xn<<'\n';
        }
        MetodaNewtonaK.close();
    }
    cout<<'\n';
    cout<<"METODA SIECZNYCH:\n";
    //metoda siecznych
    {
        cout<<"Funkcja f \n";
        double x0=0.6;
        double x1=0.7;
        double xn=1;
        fstream MetodaSiecznychF("MetodaSiecznychF.txt",ios::out);
        for(int i=0;i<M;++i)
        {
            if((f(xn)-f(x0))==0){
                cout<<"mianownik jest rowny 0!\n";
            }else{
                xn=x1-f(x1)*((x1-x0)/(f(xn)-f(x0)));
            }
            cout<<xn<<'\n';
            MetodaSiecznychF<<fixed<<setprecision(64)<<xn<<'\n';
            x0=x1;
            x1=xn;
        }
        MetodaSiecznychF.close();
    }

    {
        cout<<"Funkcja g \n";
        double x0=0.9;
        double x1=1.1;
        double xn=2;
        fstream MetodaSiecznychG("MetodaSiecznychG.txt",ios::out);
        for(int i=0;i<M;++i)
        {
            if(g(xn)-g(x0)==0){
                cout<<"mianownik jest rowny 0!\n";
            }else{
                xn=x1-g(x1)*((x1-x0)/(g(xn)-g(x0)));
            }
            cout<<xn<<'\n';
            MetodaSiecznychG<<fixed<<setprecision(64)<<xn<<'\n';
            x0=x1;
            x1=xn;
        }
        MetodaSiecznychG.close();
    }
    
    {
        cout<<"Funkcja k \n";
        double x0=3.1;
        double x1=3.2;
        double xn=1;
        fstream MetodaSiecznychK("MetodaSiecznychK.txt",ios::out);
        for(int i=0;i<M;++i){
            if((k(xn)-k(x0))==0){
                cout<<"mianownik jest rowny 0!\n";
            }else{
            xn=x1-k(x1)*((x1-x0)/(k(xn)-k(x0)));
            }
            cout<<xn<<'\n';
            MetodaSiecznychK<<fixed<<setprecision(64)<<xn<<'\n';
            x0=x1;
            x1=xn;
        }
        MetodaSiecznychK.close();
    }
    
    //bisekcja
    cout<<"BISEKCJA:\n";
    cout<<"f(x)\n";
    bisekcjaF();
    cout<<"g(x)\n";
    bisekcjaG();
    cout<<"h(x)\n";
    bisekcjaK();

    while(true)
    {
        cout<<"Wybierz wykres do narysowania:\n";
        cout<<"1 - Narysuj dla funkcji f(x)=x^3+2x^2+x-2\n";
        cout<<"2 - Narysuj dla funkcji g(x)=pow(x,2)-x;\n";
        cout<<"3 - Narysuj dla funkcji k(x)=sin(x)\n";
        int answ;
        cin>>answ;
        switch(answ)
        {
            case 1:
                std::system("python wykres.py \"MetodaNewtonaF.txt\" \"MetodaSiecznychF.txt\" \"BisekcjaF.txt\"");
                break;
            case 2:
                std::system("python wykres.py \"MetodaNewtonaG.txt\" \"MetodaSiecznychG.txt\" \"BisekcjaG.txt\"");
                break;
            case 3:
                std::system("python wykres.py \"MetodaNewtonaK.txt\" \"MetodaSiecznychK.txt\" \"BisekcjaK.txt\"");
                break;
            default:
                return 0;
        }
    }

}
