#include "Game_PvsM.h"
#include "Player.h"
#include <iostream>
using namespace std;
void Game_PvsM::Result()
{
    if ( (M).Smachine >(P1).Splayer) // let's compare there scores
        cout<<" Unfortunately ! You Lost"<<endl;
    else if ((M).Smachine < (P1).Splayer)
        cout<<"Congratulations ! You Won "<<endl;
    else
        cout<<"It's a Tie"<<endl;

}
void Game_PvsM::Game_Progress_M(Chessboard& Ch)
{

    do// every do while is a tour
    {
        Ch.ShowBoard();
        if (!(Tour%2))// the player P1 will always start the game
        {
            cout<<P1.name<<" is now playing"<<endl;
            int v=(P1).click(Ch);// P1 pick a Box
            (P1).Update_score (v);// updating his score
            cout<<P1.name<<"'s score is "<<P1.Splayer<<endl;
            cout<<"the machine's score is " << M.Smachine<<endl;
            Tour= Tour+1;
            cout<<"It's round number "<< Tour <<endl;
            cout<<"the current position is ("<<Ch.posL<<","<<Ch.posC<<")"<<endl;

        }
        else
        {
            cout << "the machine is now playing" <<endl;
            int v=M.ChoosePos(Ch);// Machine going to choose a Box
            M.Update_score(v);// updating the score of the machine
            cout<<P1.name<<"'s score is "<<P1.Splayer<<endl;
            cout<<"the machine's score is " << M.Smachine<<endl;
            Tour= Tour+1;
            cout<<"It's round number "<< Tour <<endl;
            cout<<"the current position is ("<<Ch.posL<<","<<Ch.posC<<")"<<endl;
        }
    } while (!GameOver(Ch)); //verify the end of the game
    cout<<"                                              **** GAME OVER! ****"<<endl;
    Result();
}
