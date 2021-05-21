#include "Chessboard.h"
#include <iostream>
using namespace std;
void Chessboard::ShowBoard()
{
    cout <<'\n'<<"|"<< "**" << "|";

    for(int k=0;k<nb; k++) //number of columns
    {

        if (k<10)

            cout<<'0'<<k<<"|";  //desplay the number of each column
        else

            cout<<k<<"|";
    }
  for (int i=0;i<nb; i++)
  {
      cout<<endl;
    if (i<10)
       cout<<"|"<<'0'<<i<<"|"; //deplay the number of each line
    else
       cout<<"|"<<i<<"|";
    for(int j=0;j<nb;j++)
    {
        cout<<Mat[i][j].value<<' '<<"|";
    }

  }
  cout<<endl;
  cout<<endl;
}
Chessboard::Chessboard()
{
    nb=D.RandomBox();
    for(int i=0; i<nb ; i++)//filling the chessboard with random numbers.
    {
        vector <Box> a;
        for (int j=0; j<nb; j++)
        {
            int val=rand() %9+1;
            a.push_back( Box(i,j,val)); //fill each Box with a random value between 1 and 9
        }
        Mat.push_back(a);
        a.clear();
    }
}

void Chessboard::initialize()
{
    posL=rand()%nb; //choose randomly the initial line
    posC=rand()%nb; //choose randomly the initial column
    Mat[posL][posC].changeval(); //turn on 0 the initial box's value
    cout << "The initial position is "<<'('<<posL<<','<<posC<<')'<<endl;
}
