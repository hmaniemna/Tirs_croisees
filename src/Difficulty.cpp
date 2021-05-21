#include "Difficulty.h"
#include <iostream>
using namespace std;
Difficulty::Difficulty() // try out is the level chosen by default!
{

   cout<< "Choose your level of difficulty : " <<endl;
   do
   {
     cout<<"Try-out : press 0"<<'\n'<<"Easy : press 1"<<'\n'<<"Medium : press 2"<<'\n'<<"Hard : press 3"<<endl;
     cin>>level;
   }while((level>3) || (level<0));

}
int Difficulty::RandomBox()
{
   int n;
   if (level == 0) // try out level
      n=4;    // the game is played on a 4 X 4 chessboard
   if (level==1) // the easy level
      n =  rand() %6 +  5 ; //chooses a random number between 5 and 10
   if (level == 2)//the medium level
      n=rand() %5+ 11 ; //chooses a random number between 11 and 15
   if (level==3)// the difficult level
      n= rand() %10 + 16 ;  //chooses a random number between 16 and 25

   return n;
}
