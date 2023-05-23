#ifndef GAUSS_HPP
#define GAUSS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<float> GaussElimination(std::string file,bool przestawienieWierszy=true,bool debug=false)
{
    std::vector<float> liczby;
    std::ifstream in(file);
    while(in.good())
    {
        float a;
        in>>a;
        liczby.push_back(a);
		
    }
    //zakladamy, ze plik jest poprawnie okreslony tzn. (ma n*(n+1) liczb)
    int n;
	for(int i=1;true;i++)
	{
		int j=i*(i+1);
		if(j>liczby.size())
		{
			n=i-1;
			break;
		}
	}
    //Tworzenie tablicy (x,y)
    float ** array= new float * [n+1];
    for(int i=0;i<n+1;i++)
        array[i] = new float[n];
    //przetlumaczenie macierzy jednowymiarowej na dwuwymiarowa
	for(int y=0;y<n;y++)
	{
		for(int x=0;x<n+1;x++)
        {
			array[x][y]=liczby[x+(y*(n+1))];
		}
	}
	//Algorytm Eliminacji Gaussa
	std::vector<float> s;
	if(przestawienieWierszy)
	{
		for(int x=0;x<n;x++)
			s.push_back(0);
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				if(s[x]<abs(array[y][x]))
					s[x]=abs(array[y][x]);
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(przestawienieWierszy)
		{
			float maxWiersz=0;
			int maxWierszInd=-1;
			for(int x=i;x<n;x++)
			{
				if(maxWiersz<array[i][x]/s[x])
				{
					maxWiersz=array[i][x]/s[x];
					maxWierszInd=x;
				}
			}
			if(maxWierszInd!=-1)
			{
				std::swap(s[i],s[maxWierszInd]);
				for(int j=0;j<=n;j++)
				{
					std::swap(array[j][i],array[j][maxWierszInd]);
				}
			}
		}
		for(int k=i+1;k<n;k++)
		{
			float sk=array[i][k]/array[i][i];
			for(int j=0;j<=n;j++)
			{
				array[j][k]=array[j][k]-sk*array[j][i];
			}
		}
	}
    std::vector<float> wynik;
	for(int i=0;i<n;i++)
		wynik.push_back(0);
	
	for(int i=n-1;i>=0;i--)
	{
		wynik[i]=array[n][i];
		for(int j=i+1;j<n;j++)
		{
			if(j!=i)
			{
				wynik[i]=wynik[i]-array[j][i]*wynik[j];
			}
		}
		wynik[i]=wynik[i]/array[i][i];
	}
    return wynik;
}

#endif 