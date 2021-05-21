#include "Machine.h"
#include "Vect.h"
#include <iostream>
using namespace std;
Machine::Machine()
{
    Smachine=0; //initialize the machine's score to 0
}
int Machine::ChoosePos(Chessboard& Cm) //takes in the current position of column and line
{
  int val;
  Vect V0 ; // a vector that is made to search for the maximum value in current column and line.
  Vect V1; //vector that contains all the possible boxes the machine can choose
  vector <int> V2; //a vector to help us choose which box to choose!
  Vect V3;

  if (Cm.D.level == 3 || Cm.D.level == 2) // if the level is difficult or medium
  {
    for (int j=0; j<Cm.nb  ; j++)  //to fix which column we're going to go through
    {
      for (int i=0; i<Cm.nb ; i++) //to go through each element of each line of the chosen column.
      {
        V0.v.push_back(Cm.Mat[i][j]);  //fills V0 with the elements of the column of the current line j
      }
      V0.sort();
      if ((V0.v[0].value==Cm.Mat[Cm.posL][j].value) && (V0.v[0].value!=0) ) //checks if the elements of the current line represent the maximum of each column
      {
        V1.v.push_back(Cm.Mat[Cm.posL][j]);
        V2.push_back(V0.v[0].value-V0.v[1].value); //puts the value of the difference between the biggest values of each column
      }
       V0.clear();
    }

    for (int i=0; i<Cm.nb  ; i++)  //to fix which line we're going to go through
    {
      for (int j=0; j<Cm.nb ; j++) //to go through each element of each column of the chosen line.
      {
        V0.v.push_back(Cm.Mat[i][j]);  //fills V0 with the elements of the line of the current column j
      }
      V0.sort();
      if ((V0.v[0].value==Cm.Mat[i][Cm.posC].value) & V0.v[0].value!=0 ) //checks if the elements of the current column represent the maximum of each line
      {
        V1.v.push_back(Cm.Mat[i][Cm.posC]);
        V2.push_back(V0.v[0].value-V0.v[1].value); //puts the value of the difference between the biggest values of each line
      }
      V0.clear();
    }
    if (!(V1.v.empty()))
    {
        int m=0;
        for (int i=1;i<V2.size();i++)
        {
          if (V2[i]>V2[m]) //looks for the biggest difference
            m=i;
        }
        Box Max_Box=V1.v[m];
        val=Max_Box.value;
        Update_Box(Max_Box,Cm);
    }
    if (V1.v.empty()) //the machine does not have the chance to choose a box that contains a number higher than the player
    { //in this case the machine will try to make the difference between the new values added to their scores lower!!
        Vect V01 ;
        Vect V02 ;

        for (int j=0; j<Cm.nb ; j++)
        {
            if (Cm.Mat[Cm.posL][j].value!=0)
              V01.v.push_back(Cm.Mat[Cm.posL][j]); //puts the elements of the current line/column in the list L
            if (Cm.Mat[j][Cm.posC].value!=0)
              V02.v.push_back(Cm.Mat[j][Cm.posC]);  //elements of the line will be found in positions with even number

        }
        for(int i=0;i<V01.v.size();i++)
        {
            for (int k=0; k<Cm.nb; k++)
            {
                if(Cm.Mat[V01.v[i].L][k].value!=0 && k!=V01.v[i].C)

                        V3.v.push_back(Cm.Mat[V01.v[i].L][k]);

                if (Cm.Mat[k][V01.v[i].C].value!=0 && k!=V01.v[i].L)
                        V3.v.push_back(Cm.Mat[k][V01.v[i].C]);

            }
            V3.sort();
            V2.push_back(V3.v[0].value-V01.v[i].value);
            V3.clear();
        }
        for(int i=0;i<V02.v.size();i++)
        {
            for (int k=0; k<Cm.nb; k++)
            {
                if(Cm.Mat[V02.v[i].L][k].value!=0 && k!=V02.v[i].C)

                        V3.v.push_back(Cm.Mat[V02.v[i].L][k]);

                if (Cm.Mat[k][V02.v[i].C].value!=0 && k!=V02.v[i].L)
                        V3.v.push_back(Cm.Mat[k][V02.v[i].C]);

            }
            V3.sort();
            V2.push_back(V3.v[0].value-V02.v[i].value);
            V3.clear();
        }
        int m=0;
        for (int i=1;i<V2.size();i++)
        {
          if (V2[i]<V2[m])
            m=i;
        }
        Box min_Box;
        if (m<V01.v.size())
            min_Box=V01.v[m];
        else
            min_Box=V02.v[m-V01.v.size()-1];
        val=min_Box.value;
        Update_Box(min_Box,Cm);
    }

  }
  else
  {
    for (int i=0; i<Cm.nb ; i++)
    {
      V0.v.push_back(Cm.Mat[Cm.posL][i]); //puts the elements of the current line in the vector V0
      V0.v.push_back(Cm.Mat[i][Cm.posC]); //puts the elements of the current column in the vector V0
    }
    V0.sort(); //puts the list in descending order
    val= V0.v[0].value;
    Update_Box(V0.v[0],Cm);
  }
  return val;
}
void Machine::Update_score(int val)
{
    Smachine= Smachine+val;// add the value of the current Box
}
void Machine::Update_Box(Box B, Chessboard &Cm)
{
    Cm.posL=B.L;
    Cm.posC=B.C;
    Cm.Mat[Cm.posL][Cm.posC].changeval();// the current Box can't be accessible again
}
