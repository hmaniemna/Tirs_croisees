#include "Player.h"
#include <iostream>
#include "Vect.h"
using namespace std;
Player::Player()
{
    cout << "Write your name : " << endl;
    cin >> name ;
    Splayer=0;
}
void Player::Update_score(int v)
{
    Splayer= Splayer+ v;
}
void Player::help(Chessboard Cp)
{
    int val;
    Vect V0 ;
    char res;
    cout <<"Do you need help?"<<endl;
    cout <<" press y for yes and n for no!"<<endl;
    cin>>res ;
    if (res=='y')
    {
      for (int i=0; i<Cp.D.RandomBox() ; i++)
      {
        V0.v.push_back(Cp.Mat[Cp.posL][i]); //puts the elements of the current line in the list L
        V0.v.push_back(Cp.Mat[i][Cp.posC]); //puts the elements of the current column in the list L
      }
      V0.sort(); //puts the vector in descending order
      cout << "choose "<< V0.v[0].L <<" for the new line and "<< V0.v[0].C <<" for the new column"<<endl;
    }
}
int Player::click(Chessboard& Cp)
{

    int i,j;
    do
    {
       // help(Cp);
        cout<<"Choose the Line's number : "<<endl;
        cin>>i;
        cout<<"Choose the Column's number : "<<endl;
        cin>>j;
    }
    while (verifpos(i,j, Cp)==false);
    //cout<<"the new chosen position is ("<<i<<","<<j<<")"<<endl;
    Cp.posL=i;
    Cp.posC=j;
    int e=Cp.Mat[Cp.posL][Cp.posC].value;
    Cp.Mat[Cp.posL][Cp.posC].changeval();
    return e;
}
bool Player::verifpos(int &i,int& j, Chessboard &Cp)
{
    return ((i>=0 && i<Cp.nb) && (j>=0 && j<Cp.nb) && !(i==Cp.posL && j==Cp.posC)&& (i==Cp.posL || j==Cp.posC) &&(Cp.Mat[i][j].value!=0)) ;
    // true if (i,j)is different to(posL,posC) and i is equal to the current line or j is equal to the current column
    // and the new chosen position is included in the chessboard
}
