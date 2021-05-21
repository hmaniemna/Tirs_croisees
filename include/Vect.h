#ifndef VECT_H
#define VECT_H
#include <vector>
#include "Box.h"
using namespace std;

class Vect //Vector of boxes with more developed methods
{
    public:
     std::vector <Box> v ;
    public:
     void sort(); //bubble sorting
     void clear(); //erase the content of each box in the vector
     void Showvect(); // showing the vect
};

#endif // VECT_H
