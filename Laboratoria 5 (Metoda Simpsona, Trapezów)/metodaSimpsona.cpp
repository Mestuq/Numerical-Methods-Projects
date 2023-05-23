//Damian Szopiński 185394
//Maciej Pestka 170088
#include <iostream>
#include <functional>
#include <iomanip>
#include <cmath>
using namespace std;

long double xi(long double i,long double h,long double x0)
{
    return x0+(i*h);
}
long double fi(function<long double(long double)> f,long double i,long double h,long double x0)
{
    return f(xi(i,h,x0));
}
long double Simpson(long double m,function<long double(long double)> f,long double h,long double x0)
{
    long double act=fi(f,0,h,x0);
    for(int i=0;i<=m-1;i++)
        act+=4*fi(f,2*i+1,h,x0);
    for(int i=1;i<=m-1;i++)
        act+=2*fi(f,2*i,h,x0);
    act+=fi(f,2*m,h,x0);
    act*=(h/3.0);
    return act;
}
long double Simpson(function<long double(long double)> f,long double a,long double b,long double n)
{
    long double h=(b-a)/n;
    long double m=n/2.0;
    long double x0=a;
    return Simpson(m,f,h,x0);
}

int main()
{
    cout<<setprecision(25)<<"Start\n";
 
    cout<<"Funkcja F"<<endl;
    for(int n=1;n<15;n+=1)
    {
        cout<<"n="<<n<<":"<<Simpson([](long double x){return 5+(2*x)-(8*x*x)+(x*x*x*x*x);},0,2,n)<<"\n";
    }
    cout<<"n="<<99999<<":"<<Simpson([](long double x){return 5+(2*x)-(8*x*x)+(x*x*x*x*x);},0,2,99999)<<"\n";
    cout<<"Funkcja G"<<endl;
    for(int n=1;n<15;n+=1)
    {
        cout<<Simpson([](long double x){return sin(x);},0,100,n)<<"\n";
    }
    cout<<Simpson([](long double x){return sin(x);},0,100,99999)<<"\n";
    cout<<"Funkcja H"<<endl;
    for(int n=1;n<15;n+=1)
    {
        cout<<Simpson([](long double x){return exp(x);},0,1,n)<<"\n";
    }
    cout<<Simpson([](long double x){return exp(x);},0,1,99999)<<"\n";
    return 0;
}