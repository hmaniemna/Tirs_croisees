#include "Game_PvsP.h"
#include <iostream>
using namespace std;
void Game_PvsP::Result()
{
    if (P1.Splayer > P2.Splayer) // let's compare there scores
        cout<<"The winner is "<< (P1).name <<endl;
    else if ((P1).Splayer < (P2).Splayer)
        cout<<"The winner is "<< (P2).name <<endl;
    else
        cout<<"It's a Tie"<< endl;

}
void Game_PvsP::Game_Progress_P(Chessboard Ch)
{
    do// every do_while is a tour
    {
        Ch.ShowBoard();
        if (!(Tour%2)) // the player P1 will always start the game
        {
            cout<<P1.name<<" is playing"<<endl;
            int v=P1.click(Ch);// P1 pick a Box // v is the value of the Box
            (P1).Update_score(v);//updating his score
            cout<<P1.name<<"'s score is " << P1.Splayer<<endl;
            cout<<P2.name<<"'s score is " << P2.Splayer<<endl;
            Tour= Tour+1;
            cout<<"It's round number "<< Tour <<endl;
            cout<<"the current position is ("<<Ch.posL<<","<<Ch.posC<<")"<<endl;
        }
        else
        {
            cout<<P2.name<<" is playing "<<endl;
            int v=P2.click(Ch);// P2 pick a Box
            (P2).Update_score (v);//updating his score
            cout<<P1.name<<"'s score is " << P1.Splayer<<endl;
            cout<<P2.name<<"'s score is " << P2.Splayer<<endl;
            Tour= Tour+1;
            cout<<"It's round number "<< Tour <<endl;
            cout<<"the current position is ("<<Ch.posL<<","<<Ch.posC<<")"<<endl;

        }
    } while (!GameOver(Ch));//verify the end of the game
    cout<<"                                              **** GAME OVER! ****"<<endl;
    Result();
}
