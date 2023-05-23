//Damian Szopinski 185394
//Maciej Pestka 170088
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct vec2
{
    float t,y;
};
using points = vector<vec2>;

float y(float i,points p)
{
    return p[i].y;
}
float t(float i,points p)
{
    return p[i].t;
}
float h(float i,points p)
{
    return t(i+1,p)-t(i,p);
}

vector<float> ZCeche;
float z(int i,points p)
{
    if(ZCeche.size()!=0)
    {
        return ZCeche[i];
    }
    int n=p.size()-1;
    float A[n-1], B[n-1], C[n-1],F[n-1]; //dane
    float z[n]; //znienne
    float alpha[n],beta[n]; //dane
    alpha[0]=0;
    beta[0]=0;
    alpha[n]=0;
    beta[n]=0;
    for(int a=1;a<n;a++)
    {
        A[a-1]=h(a-1,p);
        B[a-1]=2*(h(a-1,p)+h(a,p));
        C[a-1]=h(a,p);
        F[a-1]=((6.0/h(a,p))*(y(a+1,p)-y(a,p)))-((6.0/h(a-1,p))*(y(a,p)-y(a-1,p)));
    }
    z[0]=z[n]=0;
    for(int i=1;i<n;++i){
        alpha[i]=(-C[i-1])/(A[i-1]*alpha[i-1]+B[i-1]);
        beta[i]=(F[i-1]-A[i-1]*beta[i-1])/(A[i-1]*alpha[i-1]+B[i-1]);
    }
    for(int i=n-1;i>0;--i){
        z[i]=alpha[i]*z[i+1]+beta[i];
    }
    for(int i=0;i<n+1;i++){
        cout<<"Z["<<i<<"]"<<z[i]<<'\n';
    }
    for(float zv:z)
        ZCeche.push_back(zv);
    return z[i];

}

float S(int i,points p,float x)
{
    return     z(i,p)/(6.0*h(i,p)) *pow(t(i+1,p)-x,3) +  z(i+1,p)/(6.0*h(i,p)) *pow(x-t(i,p),3) +  (y(i+1,p)/h(i,p) -  z(i+1,p)*h(i,p) /6.0) *(x-t(i,p)) +  (y(i,p)/h(i,p) -   z(i,p)*h(i,p) /6.0) *(t(i+1,p)-x);
    //return ((z(i,p)/(6.0*h(i,p)))*pow(t(i+1,p)-x,3))+((z(i+1,p)/(6.0*h(i,p)))*pow(x-t(i,p),3))+(((y(i+1,p)/h(i,p))-((z(i+1,p)*h(i,p))/6.0))*(x-t(i,p)))+(((y(i,p)/h(i,p))-(((z(i,p)*h(i,p))/6.0))*(t(i+1,p)-x)));
}

void sortedPoints(points &p)
{
    for(int i=0;i<p.size()-1;i++)
    {
        if(p[i].t>p[i+1].t)
        {
            swap(p[i],p[i+1]);
            return sortedPoints(p);
        }
    }
}
int getNumberOfI(float x,points p)
{
    int act=0;
    for(int i=0;i<p.size()-1;i++)
        if(x>p[i].t)
            act=i;
    return act;
}

int main()
{
    points p;
    int n;
    cout<<"Ile prostych: ";
    cin>>n;
    for(int i=0;i<n+1;i++)
    {
        cout<<"(t"<<i<<",y"<<i<<"): ";
        float c1,c2;
        cin>>c1>>c2;
        p.push_back({c1,c2});
    }
    sortedPoints(p);
    cout<<"Sorted points by t:\n";
    for (vec2 o : p)
    {
        cout<<o.t<<" "<<o.y<<endl;
    }
    
    string command="python wykres.py momenty.txt wykres.txt "+to_string(p[0].t);

    ofstream myfile;
    myfile.open("wykres.txt");
    ofstream moments;
    moments.open("momenty.txt");
    cout<<"size "<<p[0].t<<" "<<p[p.size()-1].t<<endl;
    for(float x=p[0].t;x<=p[p.size()-1].t;x+=0.001)
    {
        if(getNumberOfI(x,p)!=getNumberOfI(x-0.001,p))
            moments<<"12\n";
        else 
            moments<<"0\n";
        myfile<<S(getNumberOfI(x,p),p,x)<<'\n';
    }
    moments.close();
    myfile.close();

    std::system(command.c_str());

    cout << "Success!" << endl;
    return 0;
}
