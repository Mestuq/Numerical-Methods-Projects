#ifndef LU_H
#define LU_H


#include "LU.h"
#include <iostream>
#include <cmath>

using namespace std;

void metodaLU() {
    int n=3;
    float l[n][n];
    float u[n][n];
    float a[n][n];
    float x[n];
    float z[n];
    float b[n];

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            u[i][j]=l[i][j]=0;
        }
    }
    a[0][0]=2;
    a[0][1]=2;
    a[0][2]=6;
    a[1][0]=2;
    a[1][1]=1;
    a[1][2]=7;
    a[2][0]=-2;
    a[2][1]=-6;
    a[2][2]=-7;
    b[0]=4;
    b[1]=6;
    b[2]=-1;
    for(int i=0; i<n; ++i) {
        l[i][i]=1;
        for(int j=i; j<n; ++j) {
            u[i][j]=a[i][j];
            for(int k=0; k<=(i-1); ++k) {
                u[i][j]-=(l[i][k]*u[k][j]);
            }
        }
        for(int j=i+1; j<n; ++j) {
            l[j][i]=a[j][i]/u[i][i];
            for (int k=0; k<=(i-1); ++k) {
                l[j][i]-=(l[j][k]*u[k][i])/u[i][i];
            }
        }

    }
    cout<<"macierz A\n";
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\nMacierz l\n";
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<l[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\nMacierz u\n";
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<u[i][j]<<' ';
        }
        cout<<'\n';
    }
    //rozwazywanie ukladu;
    for(int i=0; i<n; ++i) {
        z[i]=b[i];
        for(int j=0; j<i; ++j) {
            z[i]-=l[i][j]*z[j];
        }
        z[i]=z[i]/l[i][i];//przekatnie sa jedynkami, czyli mozna ta linike usunac
    }
    cout<<"wartosci z"<<endl;
    for(int i=0; i<n; ++i) {
        cout<<z[i]<<'\n';
    }

    for(int i=(n-1); i>=0; --i) {
        x[i]=z[i];
        for(int j=(n-1); j>i; --j) {
            x[i]-=u[i][j]*x[j];
        }
        x[i]=x[i]/u[i][i];
    }
    cout<<"wartosci x"<<endl;
    for(int i=0; i<n; ++i) {
        cout<<x[i]<<'\n';
    }



}


#endif // LU_H
