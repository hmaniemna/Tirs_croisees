#include "Vect.h"
#include <iostream>
using namespace std;
void Vect::Showvect()
{
    for (int i=0; i<v.size() ; i++)
        cout <<v[i].value<<'|';
    cout<<endl;
}
void Vect::sort()               //bubble sorting
{
    bool test=false ;
    Box b;
    int i=v.size()-1;
    while (i>=1 && !test)
    {
        test=true;
        for (int j=0; j<=i-1; j++)
        {
            if (v[j+1].value>v[j].value)
            {
                b=v[j+1];
                v[j+1]=v[j];
                v[j]=b;
            }
            test=false;
        }
        i--;
    }
}
void Vect::clear() //erase the content of each box in the vector
{
    while (!v.empty())
    {
        v.pop_back();
    }
}
