#include "Box.h"
Box::Box(){} //Constructor taking no parameters
Box::Box (int i,int j,int v) // Constructor taking three parameters i,j determine his place in the chessboard and v its value between 1 and 9
{
    value=v;
    L= i;
    C=j;
}
void Box::changeval() // change the value of the Box when it needs
{
    value=0; // the only change is that the Box not accessible any more so it takes zero as a value
}
