#ifndef FUNC_TPP
#define FUNC_TPP

template<NumericType num> num Math::Pow(num k,num v)
{
    num act=1;
    for(num i=0;i<v;i++)
        act*=k;
    return act;
}

template<NumericType num> num Math::Factorial(num x)
{
    num a=1;
    for(num i=2;i<=x;i++)
        a*=i;
    return a;
}

template<NumericType num> num Math::Sqrt(num k,int precision,num from,num to)
{
    if(to==0)//first step
    {
        from=0;
        to=k;
    }

    num middle=from+((to-from)/2.0);

    if(precision<=0)
        return middle;

    num result=middle*middle;
    if(result>k)
        return Sqrt<num>(k,precision-1,from,middle);
    if(result<k)
        return Sqrt<num>(k,precision-1,middle,to);

    return middle;
}

template<NumericType num> num Math::Sin(num x, int precision)
{
    num act = 0;
    for ( int i=1; i<precision; ++i)
    {
        int sign=(i%2==0)?-1:1;
        num k=-1+(i*2);
        act+=(Math::Pow(x,k))/Math::Factorial(k) * sign;
    }
    return act;
}

template<NumericType num> num Math::Sin2(num x, int precision)
{
    num t = x;
    num act = t;
    for ( int i=1; i<precision; ++i)
    {
        num multipl=-x*x/((2*i+1)*(2*i));
        t*=multipl;
        act+=t;
    }
    return act;
}

//! Zadanie 1
template<NumericType num> num Zadanie1::checkAcc()
{
    num act=0;
    num v=0;
    for(num i=0;true;i++)
    {
        v=1+Math::Pow<num>(1.0/2.0,i);
        if(v==1)
        {
            std::cout<<"e= 2^(-"<<i-1<<")"<<std::endl<<"1+e = ";//-1 poniewaz wynik dostajemy z poprzedniego kroku
            return act;
        }
        act=v;
    }
}


//! Zadanie 2
template<NumericType num> num Zadanie2::funF(num x)
{
    return Math::Sqrt<num>(Math::Pow<num>(x,2.0)+1.0)-1.0;
}
template<NumericType num> num Zadanie2::funG(num x)
{
    return Math::Pow<num>(x,2.0)/(Math::Sqrt<num>(Math::Pow<num>(x,2.0)+1.0)+1.0);
}

template<NumericType num> void Zadanie2::funTest()
{
    std::cout<<"-----Ex.2-----\n";
    for(int i=0;i<15;i++)
    {
        num eight=1.0/8.0;
        num x=Math::Pow<num>(eight,i);
        std::cout<<"Comparing for number "<<x<<std::endl;
        std::cout<<"F: "<<funF(x)<<std::endl;
        std::cout<<"G: "<<funG(x)<<std::endl;
    }
    std::cout<<"Funkcja G jest bardziej wiarygodna na podstawie moich testow"<<std::endl;
}

//! Zadanie 3
template<NumericType num>
num Zadanie3::funY(num x)
{
    return x-Math::Sin<num>(x);
}
template<NumericType num>
num Zadanie3::funY2(num x)
{
    return x-Math::Sin2<num>(x);
}

#endif // FUNC_TPP