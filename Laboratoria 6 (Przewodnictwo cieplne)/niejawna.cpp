#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Dla wierniejszego odtworzenia kodu w skrypcie (tam tablice zaczynały się od 1) dodałem jeden dodatkowy element do tablicy na pozycji 0

//u(x,t)=exp(-pi*pi*t)*sin(pi*x)
//t=k*M
//x from 0 to 1. Step 0.1

static float pi=3.1415926;
float dokladny(float t,float x)
{
    return exp(-1*pi*pi*t)*sin(pi*x);
}

//strona 190 Kincaid (algorytm tri)
/*
elementy przekątniowe -> d
nad przekątną -> c
pod przekątną -> a
prawa strona -> b ( u nas v )
(n,d,c,a,b)
*/
vector<float> tri(float n,vector<float> a,vector<float> b,vector<float> c,vector<float> d)
{
    vector<float> x;
    for(int i=0;i<n+1;i++)
        x.push_back(0);

    for(int i=2;i<=n;i++)
    {
        d[i]=d[i]-(a[i-1]/d[i-1])*c[i-1];
        b[i]=b[i]-(a[i-1]/d[i-1])*b[i-1];
    }
    x[n]=b[n]/d[n];
    for(int i=n-1;i>=1;i--)
        x[i]=(b[i]-(c[i]*x[i+1]))/d[i];

    return x;
}

float g(float x)
{
    return sin(pi*x);
}

//Strona 587 Kincaid (algorytm)
void start(float n,float k,float M)
{
    float h=1.0/(n+1);
    float s=k/(h*h);
    vector<float> v,a,c,d;
    for(int i=0;i<M;i++)
    {
        v.push_back(0);
        a.push_back(0);
        c.push_back(0);
        d.push_back(0);
    }
    for(int i=1;i<=n;i++)
        v[i]=g(i*h);// g to warunek początkowy w naszym przypadku sinus pi x

    float t=0;
    cout<<"-----------------------------------------\n";
    cout<<0<<" t:"<<t<<endl;
    for(int i=1;i<=n;i++)
        cout<<"v"<<i<<":"<<v[i]<<"\n";
    cout<<"\n";
    cout<<"-----------------------------------------\n";
    for(int i=1;i<=n-1;i++)
    {
        c[i]=-1*s;
        a[i]=-1*s;
    }
    for(int j=1;j<=M;j++)
    {
        for(int i=1;i<=n;i++)
            d[i]=1+2*s;
        v=tri(n,a,v,c,d);
        t=j*k;

        cout<<"j:"<<j<<" t:"<<t<<"\n";
    }
    cout<<"-----------------------------------------\n";
    for(int i=1;i<=n;i++)
        cout<<"v"<<i<<":"<<v[i]<<"\n";
    cout<<"\n";
    cout<<"Finished\n";
}


int main()
{

    cout<<"-----------------------------"<<endl;
    cout<<"Przyklad z zadania: \n";
    float pn=11;
    float pk=0.005125;
    float pM=200;
    start(pn,pk,pM);
    cout<<"-----------------------------"<<endl;
    cout<<"Przyklad z zadania 2: \n";
    pk=0.006;
    pM=171;
    start(pn,pk,pM);
    cout<<"-----------------------------"<<endl;

    cout<<"Interfejs uzytkowanika \n";

    cout<<"Podaj wartosc n: ";
    float n;
    cin>>n;
    cout<<"Podaj wartosc k";
    float k;
    cin>>k;
    cout<<"Podaj wartosc M";
    float M;
    cin>>M;
    start(n,k,M);
    return 0;
}
