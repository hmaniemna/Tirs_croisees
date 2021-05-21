#include "Game.h"
#include <iostream>
#include "Game_PvsM.h"
#include "Game_PvsP.h"
using namespace std;
Game::Game()
{
    Tour = 0;
}
char Game::ChoosePlayer()
{
    char c;
    cout<<"Choose your opponent"<<endl;
    cout<<"press M for machine or P for player"<<endl;
    cin>> c;
    return c; // return the choice of the player
}
void Game::Game_progress(Chessboard Ch)
{
    char c;
    do
    {
        c= ChoosePlayer();// as a first step Player P1 have to choose his opponent
    }
    while (c!='M'&& c!='P' && c!='m' && c!='p');
    Ch.initialize();//the machine point randomly on a box as a first step
    if (c=='M' || c=='m')//P1 choose to play with a machine
    {
        Game_PvsM GM; //instantiate a game between player and machine GM
        GM.Game_Progress_M(Ch);
    }
    if (c=='P' || c=='p')//P1 choose to play with another player
    {
        Game_PvsP GP;//instantiate a game between player and another player GP
        GP.Game_Progress_P(Ch);
    }
}
bool Game::GameOver(Chessboard Ch)
{
    int i=0;
    do
    {
        i++;
    }
    while((Ch.Mat[Ch.posL][i].value==0)&& (Ch.Mat[i][Ch.posC].value==0));
    return i==Ch.nb;
}
