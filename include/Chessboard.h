#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Difficulty.h"
#include "Box.h"
#include <vector>
using namespace std;

class Chessboard
{
    public:
     Difficulty D;
     int nb,posL,posC; // nb=number of boxes , posL= current line, posC= current column
     vector < vector <Box> > Mat;

    public:
     Chessboard(); // the constructor
     void ShowBoard();//desplay the chessboard
     void initialize();//the machine chooses the initial position of the game
};
#endif // CHESSBOARD_H
