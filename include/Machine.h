#ifndef MACHINE_H
#define MACHINE_H
#include "Chessboard.h"
#include "Box.h"
class Machine
{
public:
  int Smachine; // machine's score
public:
  Machine() ; // constructor
  int ChoosePos(Chessboard&) ; //takes in the current position of column and line
  void Update_score(int);// updating the score of machine
  void Update_Box(Box,Chessboard&);// update the current position
};
#endif // MACHINE_H
